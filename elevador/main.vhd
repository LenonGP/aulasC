library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity main is
    Port (
        clk : in std_logic; -- Sinal de clock
        reset : in std_logic; -- Sinal de reset
        botao_andar_0 : in std_logic; -- Boto do andar 1
        botao_andar_1 : in std_logic; -- Boto do andar 2
        botao_andar_2 : in std_logic; -- Boto do andar 3
        botao_andar_3 : in std_logic; -- Boto do andar 4
        botao_terreo : in std_logic; -- Boto especfico para o terreo
        botao_elev_0 : in std_logic; -- Boto para ir para o andar 1
        botao_elev_1 : in std_logic; -- Boto para ir para o andar 2
        botao_elev_2 : in std_logic; -- Boto para ir para o andar 3
        botao_elev_3 : in std_logic; -- Boto para ir para o andar 4
        botao_elev_terreo : in std_logic; -- Boto especfico para ir ao terreo		  
        aberto : inout std_logic; -- Sinal para indicar portas abertas
        andar_atual : inout integer range 0 to 4; -- Sinal para indicar o andar atual
        fechar_porta : inout std_logic; -- Boto para fechar a porta
        leds : out STD_LOGIC_VECTOR(6 downto 0) -- Sada para o display de 7 segmentos
    );
end main;

architecture Behavioral of main is

    component disp
        port (n : in integer range 0 to 15;
              leds : out STD_LOGIC_VECTOR(6 downto 0));
    end component;

    type estado_elevador is (parado, subindo, descendo, porta_aberta, fechando_porta);
    signal estado_atual : estado_elevador;
    signal prox_andar : integer range 0 to 4;
    signal chamada : std_logic_vector(4 downto 0) := (others => '0');

begin

    u1 : disp port map (andar_atual, leds);

    process(clk, reset)
    begin
        if reset = '1' then
            estado_atual <= parado;
            andar_atual <= 0;
            aberto <= '0';
        elsif rising_edge(clk) then
            -- Lgica para atender chamadas do elevador
            if botao_terreo = '1' then
                chamada(0) <= '1';
            end if;

            if botao_andar_0 = '1' then
                chamada(0) <= '1';
            elsif botao_andar_1 = '1' then
                chamada(1) <= '1';
            elsif botao_andar_2 = '1' then
                chamada(2) <= '1';
            elsif botao_andar_3 = '1' then
                chamada(3) <= '1';
            end if;

            case estado_atual is
                when parado =>
                    if botao_andar_0 = '1' then
                        prox_andar <= 0;
                        estado_atual <= subindo;
                    elsif botao_andar_1 = '1' then
                        prox_andar <= 1;
                        if andar_atual < prox_andar then
                            estado_atual <= subindo;
                        else
                            estado_atual <= descendo;
                        end if;
                    elsif botao_andar_2 = '1' then
                        prox_andar <= 2;
                        if andar_atual < prox_andar then
                            estado_atual <= subindo;
                        else
                            estado_atual <= descendo;
                        end if;
                    elsif botao_andar_3 = '1' then
                        prox_andar <= 3;
                        estado_atual <= descendo;
                    end if;
                when subindo =>
                    if andar_atual < prox_andar then
                        andar_atual <= andar_atual + 1;
                    else
                        estado_atual <= porta_aberta;
                        aberto <= '1';
                    end if;
                when descendo =>
                    if andar_atual > prox_andar then
                        andar_atual <= andar_atual - 1;
                    else
                        estado_atual <= porta_aberta;
                        aberto <= '1';
                    end if;
                when porta_aberta =>
                    aberto <= '1';
                    fechar_porta <= '1';
                    if chamada(andar_atual) = '1' then
                        chamada(andar_atual) <= '0';
                    end if;
                    estado_atual <= fechando_porta;
                when fechando_porta =>
                    fechar_porta <= '0';
                    aberto <= '0';
                    estado_atual <= parado;
            end case;
        end if;
    end process;

end Behavioral;
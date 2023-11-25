# Projeto de Monitoramento de Geladeira para Controle de Vacinas com Arduino 🌡️🚪

## Descrição do Projeto

Bem-vindo ao projeto de monitoramento de geladeira desenvolvido no primeiro semestre do curso de Engenharia de Software da FIAP. Este projeto utiliza a plataforma Arduino para monitorar a temperatura interna da geladeira e determinar se a porta está aberta ou fechada. O principal objetivo é fornecer um controle eficiente para o armazenamento de vacinas, garantindo que as condições ideais sejam mantidas.

## Funcionalidades

1. **Monitoramento de Temperatura:**
   - O sensor de temperatura integrado ao Arduino mede a temperatura interna da geladeira.
   - Os dados são exibidos em tempo real no display conectado ao Arduino.

2. **Detecção de Porta Aberta/Fechada:**
   - Um sensor magnético identifica se a porta da geladeira está aberta ou fechada.
   - O status da porta é indicado no display, facilitando a verificação rápida.

3. **Alarme de Porta Aberta:**
   - Caso a porta permaneça aberta por um tempo pré-determinado, um alarme sonoro é acionado para alertar sobre a situação.

4. **Controle Remoto:**
   - Possibilidade de integração com um módulo de comunicação sem fio para monitoramento remoto via aplicativo ou plataforma online.

## Hardware Utilizado

- Arduino Uno
- Sensor de Temperatura DS18B20
- Sensor Magnético para Porta
- Display LCD 16x2
- Buzzer para Alarme Sonoro

## Instruções de Montagem

1. **Conexão dos Sensores:**
   - Conectar o sensor de temperatura à porta digital do Arduino.
   - Conectar o sensor magnético à porta digital correspondente.
   - Conectar o display LCD ao Arduino.
   - Conectar o buzzer à porta digital para o alarme.

2. **Configuração do Código:**
   - Certificar-se de ajustar as configurações de calibração do sensor de temperatura conforme necessário.
   - Configurar o tempo para acionamento do alarme de porta aberta.

3. **Upload do Código:**
   - Carregar o código fornecido no Arduino IDE para o Arduino Uno.
   - Verificar se todas as bibliotecas necessárias estão instaladas.

4. **Testes:**
   - Realizar testes para garantir que o monitoramento de temperatura e a detecção de porta estejam funcionando corretamente.

## Contribuições e Melhorias

Este projeto está em constante desenvolvimento, e contribuições são bem-vindas. Se você identificar melhorias ou tiver sugestões para novas funcionalidades, sinta-se à vontade para contribuir.

## Licença

Este projeto é licenciado sob a [Licença MIT](LICENSE).

## Contato

Para mais informações ou dúvidas, entre em contato com o desenvolvedor:

- Nome: [Seu Nome]
- E-mail: [seuemail@example.com]
- GitHub: [seuusername](https://github.com/seuusername)

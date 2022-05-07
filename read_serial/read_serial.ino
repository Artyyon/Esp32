/* Leitura da porta serial usb conctada com o Esp32
 * Nesse arquivo planejo criar um sketch de leitura de porta seria completa
 * para retirar a necessidade de ler na função loop
 */

#define LD_1 18

// Variaveis globais
String frase("");

// Função para ligar led com resposta da porta serial
bool turn_on_light(String input){
  if(input == "on"){
    digitalWrite(LD_1, HIGH);
    Serial.println("Luz -> Ligada");
    return 1;
  }else if(input == "off"){
    digitalWrite(LD_1, LOW);
    Serial.println("Luz -> Desligada");
    return 1;
  }
  Serial.println("Comando não reconhecido");
  return 0;
}

void setup() {
  // Inicialização da porta serial
  Serial.begin(9600);

  pinMode(LD_1, OUTPUT);
  
  Serial.println("Art - Esp32");
}

void loop() {
  // Verifica se tem movimentação de dados pela porta serial
  if(Serial.available() > 0){
    // Le de forma de loop a string de entrada
    char aux = Serial.read();

    // Verificação de estado de parada
    if(aux != '\n'){
      // Concatena entrada em uma variavel final
      frase = frase + aux;
      
    }else{
      // Imprime na tela o texto recebido pela porta serial
      Serial.print("Recebido pela porta serial: ");
      Serial.println(frase);

      // Chamada de função de controle de luz
      if (turn_on_light(frase) != 1){
        Serial.println("Erro: função turn_on_light() não foi executada corretamente");
      }
      
      // Reseta a variavel frase para poder receber novos dados
      frase = String("");
    }
  }
}

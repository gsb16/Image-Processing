# Processamento com filtros em imagens pmg

## Gabriel Barreto - GRR20166812

## Objetivos:
Projeto da disciplina ci067 de 2016/2
- Aplicação de filtros em imagens pmg;
- Prática com tratamento e processamento de imagens;
- Tratamento de parâmetros em CLI;

## Compilação:
- *make:* compilação do código e criação dos executáveis "filtronegativo, filtrolimiar, filtromedia e filtromediana"
- *make clean:* remove arquivos temporários
- *make purge:* executa o make clean e deleta o executável
- Obs.: Com *make* filtro<nome> é possível compilar apenas um filtro específico

## Execução:
- Os parâmetros do comando podem ser colocados de formas variadas
- Usar o nome do filtro desejado em filtro<nome> como no exemplo "filtronegativo"
```
// entrada e saída em arquivos
./filtro<nome> -i inputfile.pgm -o outputfile.pgm
./filtro<nome> -o outputfile.pgm -i inputfile.pgm
```
```
// entrada em arquivo, saída em stdout, vice-versa ou ambos
./filtro<nome> -i inputfile.pgm > outputfile.pgm
./filtro<nome> -o outputfile.pgm < inputfile.pgm
./filtro<nome> < inputfile.pgm > outputfile.pgm
``` 
- O filtro limiar necessita de um valor N para o parâmetro -l
- Na ausência de um valor, o limiar padrão é 0.5
```
./filtrolimiar -l N -i input -o output
``` 
 
## Bugs conhecidos:
- O filtro de redução de ruído por mediada não está funcionando

## Implementação pendente:
- Um filtro para executar rotação em 90 graus nas imagens

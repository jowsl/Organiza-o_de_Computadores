#lang racket
(define (start n m)
  (set! lower (min n m))
  (set! upper (max n m))
  (guess))
(define lower 1) ;; define usada para definir variáveis ou funcões. Define é similar ao Let.
(define upper 999999) ;; define para variáveis globais e let para locais. let pode ser usada para atribuir
(define (guess) ;; Declarando função guess   ;; o valor de uma variável a outra usando o *let
  (quotient (+ lower upper) 2)) ;; quotient retorna o valor da divisão de dois números INTEIROS.
(define (smaller)
  (set! upper (max lower (sub1 (guess)))) ;; set! é um comando para alterar o valor de variáveis
  (guess))                                ;; em geral set! aparece como (set! variável expressão)
#|Nessa função (smaller) estamos setando o novo valor para upper.
(sub1 (guess)) faz com que seja subtraido 1 do valor calculado pela função (guess).
A função (max x y) me da o valor máximo entre os dois valores. Logo upper será atualizado pelo
valor de guess menos 1.
|#
(define (bigger)
  (set! lower (min upper (add1 (guess))))
  (guess))
#| Da mesma forma, temos o lower atualizado, que será o valor mínimo entre o upper que era 100, e o
valor do  guess + 1, ou seja, se responder-mos que o valor é (bigger) que 50, então o novo lower será
 51 (o guess+1), esse 51 será atualizado para o nosso novo lower, enquanto o upper continuaria 100. |#

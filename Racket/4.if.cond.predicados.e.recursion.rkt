#lang racket
(string=? "Hello world" "teste")
(zero? 0)
(boolean? "false")
(rational? 2/3)
(equal? (- 39 36) (+ 2 1))
;; comando equal pode ser usado para comprar qualquer coisa.
(define x 11)
(define y "Hello")
(equal? x y)
;; repare que o (equal? funciona para tudo, porém o (= so funciona para numeros.
(set! y 10)
(= x y)


;; O If em racket, tudo que não é falso, é verdadeiro.
(if '(1) ;; 1 conta como true
    "Tudo que não é falso é verdadeiro"
    "A vai se fuder")
(if empty ;; empty não é falso, logo é true.
    "Tudo que não é falso é verdadeiro"
    "A vai se fuder")
(if false
    "Tudo que não é falso é verdadeiro"
    "A vai se fuder")
(if false "Tudo que não é falso é verdadeiro" "Vai se fuder")
(if (odd? 5) 'Sim 'Não)
;; O padrão de if é (if expressão1 expressão2 expressão3) onde 1 é o "teste", 2 "então" e 3 "ou".
;; A função if avalia apenas um dos dois ramos. ou a expressão2 ou a expressão3.
;; pode-se fazer if aninhado igual outras linguagens, mas o (cond é mais usado em racket.
(if (even? x)
    'even-number.
    (if (= x 11)
        'x=11
        'odd-number-that-isnt-11))
    

;; COND é a melhor forma de fazer condições aninhadas, porque so precisa de um (cond
(set! x 24)
(cond [(equal? x 10) "são iguais"]
      [(odd? x) "é número impar"]
      [else "beep boop boop"])


;; recursion is used to make list-eaters. Usamos para pegar o começo da lista e mandar o resto
;; dessa mesma lista para a mesma função até que a lista e esteja vazia.
;; (my-length determina o tamanho da lista.
(define (my-length a-list)
  (if (empty? a-list)
      0
      (add1 (my-length (rest a-list)))))
(my-length (list 'a 'b))
(my-length (cons 'a (cons 'b empty)))
(add1 (my-length (rest (cons 'a (cons 'b empty)))))
(add1 (my-length (cons 'b empty)))
(add1 (my-length empty))
(add1 (add1 0))
(add1 1)
2




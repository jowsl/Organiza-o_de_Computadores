#lang racket
;; Em racket, structures funcionam de forma similar as em C tendo o seguinte formato
;; ex: lista com dados de estudantes (struct estudante (nome matricula dormitorio))
(struct estudante(nome matricula dormitorio)) ;; field = nome matricula e dormitorio
(define novato1(estudante 'Jow 12345 'RepTroia)) ;; dados dos fields
;; Assim, todas inforações do estudante novato estão armazenadas e pode ser chamada assim
;;(estudante-xxx novato) onde xxx vai ser substituido pelo dado contidos no "field" (struct. exemplo:
;;(estudante-dormitorio novato)

(define Bruxo(estudante 'Bruxo 453623 "Rep Troia"))
(define Dya(estudante 'DyaÚtil 565656 "Rep Troia"))
(define Mary(estudante 'Mary 6785 "Rep Alem da Lenda"))
(define IsBad(estudante 'TaRuim 8888 "Rep Troia"))
(define estudante-naSala (list Bruxo Dya Mary IsBad))

#|(struct estudantes-geral (novato junior veteranos decanos))
(define todos-estudantes
  (estudantes-geral (list novato1 (estudante 'Mary 6785 "Rep Alem Da Lenda"))
                    (list (estudante 'Bruxo 453623 "Rep Troia"))
                    (list (estudante 'DyaÚtil 565656 "Easy Chicken"))
                    '()))
Não funcionou??
|#

;; Para tornar uma estrutura visível no paine de interativiade ---->
;; temos que adicionar #:transparent antes de fechar o parenteses do (struct ..... #:transparent)
(struct teste (x y z)) ;; criando struct
(define x01 (teste 1 2 3)) ;; definindo os valores para o x y z da estrutura teste.
;; ao chamar o interative panel o resultado será #<teste>
;; com o transparent no final teremos o valores de x y z.
(struct teste2 (j k l) #:transparent) ;; os nomes da estrutura e suas variáveis devem ser diferentes.
(define x02 (teste2 3 4 5))

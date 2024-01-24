#lang racket
(define x 3)
(define is-it-even #f)
(or (odd? x) (set! is-it-even #t)) ;; similar ao C, or e and tem funções parecidas em racket
(and (odd? x) (set! is-it-even 19)) ;; o (or so precisa de uma condição seja "t" enquanto (and 
;; checa todas. O (and para assim que encontra uma falsa e retorna o #f.
;; a condição (when é basicamente um (if sem o (else. ja a (unless é o contrario de (when.
#|    um exemplo de unless
(define filename "my.first.program.rkt")
(unless (ask-use-whether-to-keep-file filename)
  (delete-file filename))

(unless so faz a ação se a condição for um #f
|#
(if (member x '(5 y z)) 'ok 'no-ok) ;; commando member verifica se x(5) é membro da lista.

(member x '(5 y z)) ;; entertanto a função member retorna o resto da lista junto com o item procurado
;; pode parecer estranho mas isso pode ser interessante em alguns cassos. Como uma tasklist.

(member 2 '(1 trabalho 2 comer 3 lavar louças 4 passear com a Pandora))

(struct point (x y) #:transparent)
(define pointA (point 0 0))
;; Ao criar uma (struct point abre um leque de novos comandos como point-x, point-y, point?, point.
(define (distance-to-origin p)
  (sqrt (+ (sqr (point-x p)) (sqr (point-y p)))))
(define pt1 (point -1 2))  ;; para comprar os x de cada um desses dois pontos 
(define pt2 (point -1 2))  ;; deve-se usar (equal? (point-x pt1) (point-x pt2))

;; as vezes é interesante descobrir se uma a peça da estrutura foi criada junta ou separada.
;; para isso existe o comando (eq?

(eq? pt1 pt2) ;; retornará #f ja que ambas foram criadas em momentos diferentes.
(eq? pt1 pt1) ;; criadas em um mesmo momento, retorna #t.
;; pode-se também definir um novo nome para um valor existente.
(define pt3 pt1)
(eq? pt3 pt1) ;; #t

(define (eq-first-items list1 list2)
  (eq? (first list1) (first list2)))
(eq-first-items (cons pt1 empty) (cons pt3 empty)) ;; retorna true
(eq-first-items (cons pt1 empty) (cons pt2 empty)) ;; retorna false
#| Avaliando oque aconteceu:
o define (eq-first-items list1 list2) vai ter a função de checar se o primeiro item de cada lista
são criados no mesmo momento. Isso esta descrito na linha logo abaixo onde esta descrito oque a
função irá fazer. (eq? (first list1) (first list2)).
Assim, quando a função é chamada para avaliar as listas pt1 e pt3 ela retornará #t uma vez que defi-
nimos o pt3 igual ao pt1 na linha 36.
Logo, quando verificamos pt1 e pt2, teremos um #f. O mesmo ocorreria para pt2 e pt3. |#
(eq-first-items (cons pt2 empty) (cons pt3 empty))

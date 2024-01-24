#lang racket
(require 2htdp/universe 2htdp/image)
(define WIDTH 200)
(define HEIGHT 300)



(define fundo (empty-scene WIDTH HEIGHT))
(define (teste)
  (put-image (ellipse 60 30 "solid" "blue") (/ WIDTH 2) (- HEIGHT 20)#|fundo|#))
(define (cena-circulo)
  (put-image (circle 13 "solid" "red") (/ WIDTH 2) (- HEIGHT 10) (teste)))
(define (cena-ufo)
(put-image (text "UFO" 10 "white") (/ WIDTH 2) (- HEIGHT 10) (cena-circulo)))

(define (add3toState current-state)
  (+ current-state 3))

(define (desenhar-ufo current-state)
  (place-image cena-ufo (/ WIDTH 2) current-state
               (empty-scene WIDTH HEIGHT)))

(big-bang 0
  (on-tick add3toState)
  (to-draw desenhar-ufo))

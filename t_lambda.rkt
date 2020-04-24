#lang scheme

; apply some function in shceme-context
(define stxt_Id  (lambda (f) (f "Identity"))) 
(define stxt_T/F (lambda (f) ((f "True") "False"))) 

(define I (lambda (x) x))     ; Identity
(define M (lambda (f) (f f))) ; Mockingbird
(define K  (lambda (p) (lambda(q) p))) ; Kestrel
(define KI (lambda (p) (lambda(q) q))) ; Kite

(define C (lambda (f) (lambda(a) (lambda(b) ((f b) a))))) ; Cardinal

(define T K) ; True
(define F KI) ; False

(define NOT (lambda (p) ((p F) T))) 

;;;;;;;;;;;;;;;;
 
((I I) 42) ; 42
(stxt_Id (I I)) ; "Identity"
(stxt_Id (M I)) ; "Identity"
(newline)

((K  I) M) ; procedure I
((KI M) I) ; procedure I
(newline)

( (KI   M) C) ; procedure C
(((K I) M) C) ; procedure C
(((C K) M) C) ; procedure C
(newline)

(NOT T) ; procedure KI
(C K)   ; #<procedure:...
(stxt_T/F (NOT T)) ; "False"
(stxt_T/F (C   K)) ; "False"
(newline)
(NOT F) ; procedure K
(C F)   ; #<procedure:...
(stxt_T/F (NOT F)) ; "True"
(stxt_T/F (C   F)) ; "True"

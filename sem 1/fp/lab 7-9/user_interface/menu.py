import textwrap

class MENU:
    def print_main_menu():
        print(textwrap.dedent("""
        Catalog studenti:

        Optiuni:
            1. Gestionare Studenti
            2. Gestionare Discipline
            3. Asignare note
            4. Statistici
            5. Iesire
        """))

    def print_student_menu():
        print(textwrap.dedent("""
        Gestionare Studenti:

        Optiuni:
            0. Afisare studenti
            1. Adaugare student
            2. Stergere student
            3. Modificare nume
            4. Cautare 
            5. Back
            6. Random
        """))

    def print_subject_menu():
        print(textwrap.dedent(""" 
        Gestionare Discipline:

        Optinui:
            0. Afisare discipline
            1. Adaugare disciplina
            2. Stergere disciplina
            3. Modificare nume
            4. Modificare profesor
            5. Cautare 
            6. Back
        """))

    def print_grades_menu():
        print(textwrap.dedent("""
        Note:
        
        Optiuni:
            0. Afisare note studenti
            1. Notare
            2. Back
        """))

    def print_statistic_menu():
        print(textwrap.dedent("""
        Statistici:

        Optiuni:
            1. Lista studenti si note la o disciplina
            2. Studenti ordonati alfabetic dupa nume
            3. Studenti ordonati dupa nota la o disciplina
            4. Top 20% studenti dupa media notelor
            5. Back
        """))




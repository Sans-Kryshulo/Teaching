Sub CreateBiosensorPresentationWithImages()
    Dim ppt As Object
    Dim slide As Object
    Dim slideIndex As Integer
    Dim imagePath1 As String
    Dim imagePath2 As String

    ' Шлях до зображень (оновіть відповідно до ваших шляхів до файлів)
    imagePath1 = "C:\Users\dimar\OneDrive\Рабочий стол\1.png"  ' Зображення мультисенсора
    imagePath2 = "C:\Users\dimar\OneDrive\Рабочий стол\2.png"  ' Електронно-мікроскопічне зображення наночастинок

    ' Створення нової презентації
    Set ppt = New PowerPoint.Application
    ppt.Visible = True
    ppt.Presentations.Add
    slideIndex = 1

    ' Слайд 1: Тема
    Set slide = ppt.ActivePresentation.Slides.Add(slideIndex, 1)
    slide.Shapes.Title.TextFrame.TextRange.Text = "Сучасні досягнення напівпровідникових біосенсорів"
    slide.Shapes.Placeholders(2).TextFrame.TextRange.Text = "Автор: [Ваше ім'я]"

    ' Слайд 5: Іон-селективні польові транзистори для діагностики
    slideIndex = slideIndex + 1
    Set slide = ppt.ActivePresentation.Slides.Add(slideIndex, 1)
    slide.Shapes.Title.TextFrame.TextRange.Text = "Іон-селективні польові транзистори"
    slide.Shapes.Placeholders(2).TextFrame.TextRange.Text = "Мультисенсор для діагностики дисфункції нирок."
    slide.Shapes.AddPicture(imagePath1, MsoTriState.msoFalse, MsoTriState.msoCTrue, 100, 100, 400, 300)
    slide.Shapes.AddTextbox(msoTextOrientationHorizontal, 100, 420, 400, 50).TextFrame.TextRange.Text = "Мультисенсор для визначення концентрацій метаболітів."

    ' Слайд 6: Використання наночастинок золота
    slideIndex = slideIndex + 1
    Set slide = ppt.ActivePresentation.Slides.Add(slideIndex, 1)
    slide.Shapes.Title.TextFrame.TextRange.Text = "Використання наночастинок золота"
    slide.Shapes.Placeholders(2).TextFrame.TextRange.Text = "Наночастинки золота покращують характеристики біосенсорів."
    slide.Shapes.AddPicture(imagePath2, MsoTriState.msoFalse, MsoTriState.msoCTrue, 100, 100, 400, 300)
    slide.Shapes.AddTextbox(msoTextOrientationHorizontal, 100, 420, 400, 50).TextFrame.TextRange.Text = "Наночастинки золота розміром 20 нм і 30 нм."

    ' Слайд 7: Оптимізація біоселективних елементів
    slideIndex = slideIndex + 1
    Set slide = ppt.ActivePresentation.Slides.Add(slideIndex, 1)
    slide.Shapes.Title.TextFrame.TextRange.Text = "Оптимізація біоселективних елементів"
    slide.Shapes.Placeholders(2).TextFrame.TextRange.Text = "Графік впливу наночастинок на характеристики біосенсорів."

    ' Слайд 8: Практичне застосування
    slideIndex = slideIndex + 1
    Set slide = ppt.ActivePresentation.Slides.Add(slideIndex, 1)
    slide.Shapes.Title.TextFrame.TextRange.Text = "Практичне застосування біосенсорів"
    slide.Shapes.Placeholders(2).TextFrame.TextRange.Text = "Біосенсори у медичній діагностиці та екологічному моніторингу."

    ' Слайд 9: Розробка біосенсорів в Україні
    slideIndex = slideIndex + 1
    Set slide = ppt.ActivePresentation.Slides.Add(slideIndex, 1)
    slide.Shapes.Title.TextFrame.TextRange.Text = "Розробка біосенсорів в Україні"
    slide.Shapes.Placeholders(2).TextFrame.TextRange.Text = "Схема установки для кондуктометричних вимірювань."

    ' Слайд 10: Ефективність біосенсорів
    slideIndex = slideIndex + 1
    Set slide = ppt.ActivePresentation.Slides.Add(slideIndex, 1)
    slide.Shapes.Title.TextFrame.TextRange.Text = "Ефективність сучасних біосенсорів"
    slide.Shapes.Placeholders(2).TextFrame.TextRange.Text = "Порівняння характеристик біосенсорів з наночастинками золота."

    ' Можна додати ще більше слайдів з описом або іншими зображеннями...

End Sub

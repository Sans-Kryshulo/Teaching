using System;
using System.Collections.Generic;

namespace EnglishFrenchDictionaryApp
{
    public class DictionaryManager
    {
        private Dictionary<string, List<string>> dictionary;

        public DictionaryManager()
        {
            dictionary = new Dictionary<string, List<string>>();
        }

        public void AddWord(string englishWord, List<string> frenchTranslations)
        {
            if (!dictionary.ContainsKey(englishWord))
            {
                dictionary.Add(englishWord, frenchTranslations);
                Console.WriteLine($"Слово '{englishWord}' и его переводы успешно добавлены.");
            }
            else
            {
                Console.WriteLine($"Слово '{englishWord}' уже существует.");
            }
        }

        public void RemoveWord(string englishWord)
        {
            if (dictionary.ContainsKey(englishWord))
            {
                dictionary.Remove(englishWord);
                Console.WriteLine($"Слово '{englishWord}' было успешно удалено.");
            }
            else
            {
                Console.WriteLine($"Слово '{englishWord}' не найдено.");
            }
        }

        public void RemoveTranslation(string englishWord, string frenchTranslation)
        {
            if (dictionary.ContainsKey(englishWord))
            {
                var translations = dictionary[englishWord];
                if (translations.Remove(frenchTranslation))
                {
                    Console.WriteLine($"Перевод '{frenchTranslation}' для слова '{englishWord}' был успешно удален.");
                    if (translations.Count == 0)
                    {
                        dictionary.Remove(englishWord);
                        Console.WriteLine($"Слово '{englishWord}' было удалено, так как у него не осталось переводов.");
                    }
                }
                else
                {
                    Console.WriteLine($"Перевод '{frenchTranslation}' для слова '{englishWord}' не найден.");
                }
            }
            else
            {
                Console.WriteLine($"Слово '{englishWord}' не найдено.");
            }
        }

        public void UpdateWord(string oldEnglishWord, string newEnglishWord)
        {
            if (dictionary.ContainsKey(oldEnglishWord))
            {
                var translations = dictionary[oldEnglishWord];
                dictionary.Remove(oldEnglishWord);
                dictionary.Add(newEnglishWord, translations);
                Console.WriteLine($"Слово '{oldEnglishWord}' было успешно изменено на '{newEnglishWord}'.");
            }
            else
            {
                Console.WriteLine($"Слово '{oldEnglishWord}' не найдено.");
            }
        }

        public void UpdateTranslation(string englishWord, string oldTranslation, string newTranslation)
        {
            if (dictionary.ContainsKey(englishWord))
            {
                var translations = dictionary[englishWord];
                int index = translations.IndexOf(oldTranslation);
                if (index != -1)
                {
                    translations[index] = newTranslation;
                    Console.WriteLine($"Перевод '{oldTranslation}' для слова '{englishWord}' был успешно изменен на '{newTranslation}'.");
                }
                else
                {
                    Console.WriteLine($"Перевод '{oldTranslation}' для слова '{englishWord}' не найден.");
                }
            }
            else
            {
                Console.WriteLine($"Слово '{englishWord}' не найдено.");
            }
        }

        public List<string> GetTranslations(string englishWord)
        {
            if (dictionary.TryGetValue(englishWord, out var translations))
            {
                return translations;
            }
            else
            {
                Console.WriteLine($"Слово '{englishWord}' не найдено.");
                return null;
            }
        }
    }
}

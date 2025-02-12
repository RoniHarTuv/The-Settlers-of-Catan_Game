# The-Settlers-of-Catan Game
"Settlers of Catan" is a familiar board game. This project presents an implementation for the game. Attached is a "Readme" file and a file showing the game board. In this project, the use of inheritance, classes and functions are mainly reflected in ritual.

המתיישבים של קטאן הוא משחק קופסא ל-3 עד 4 שחקנים המשלב הן חשיבה אסטרטגית, ניהול משאבים ויכולת מסחר. מטרת המשחק היא לצבור ראשון 10 נקודות ניצחון. את הוראות המשחק המלא ניתן למצוא כאן: https://www.hakubia.com/wp-content/uploads/2021/01/%D7%A7%D7%98%D7%90%D7%9F.pdf.

__חוקי המשחק__

המשחק מורכב מלוח המכיל 19 חלקות אדמה מוקפות בים. כל חלקת אדמה נותנת משאב כלשהו (חוץ מהמדבר). חלקות האדמה במשחק הן: יער (מניב עץ), גבעות (מניבות לבנים), אדמת מרעה (מניבה צמר), אדמה חקלאית (מניבה שיבולת), הרים (מניבים ברזל), מדבר (לא מניב כלום). כל חלקי המפה מקבלים מספר כלשהו בין 2 ל-12.
קלפים, יישובים, ערים ומשאבים

כל שחקן בעל משאבים (כגון שיבולת, ברזל, לבנים וכו') יכול לרכוש איתם דברים שונים במשחק כמו קלפי פיתוח, יישובים, ערים ודרכים.
קלף פיתוח: מחירו של קלף פיתוח הוא ברזל 1, צמר 1 ושיבולת 1. השחקן יכול לקבל אחד מ-3 סוגים שונים של קלפים: 1. קלף קידום: זהו קלף המעניק הטבה לשחקן (לאחר מכן הקלף יורד מידיו של השחקן). בין הקלפים הללו ניתן למצוא: מונופול - השחקן בוחר משאב כלשהו וכל שאר השחקנים מחוייבים להעביר לו את המשאב הזה. בניית דרכים - השחקן יכול לבנות 2 דרכים במפה ללא עלות. שנת שפע - השחקן זוכה לקבל מהבנק שני קלפים של משאבים שיש לו הכי מעט מהם. 2. אבירים - שחקן המחזיק ב-3 קלפים כאלה, מקבל את קלף הצבא הגדול ביותר המקנה לו 2 נקודות ניצחון (יש בדיוק 3 קלפים כאלה). 3. קלפי נקודות ניצחון - יש 4 קלפים שונים המעניקים נקודת ניצחון למי שמחזיק בהם.
    בנייה: ניתן לבנות דרכים, ערים ויישובים בצורה הבאה: 1. קטע דרך: עלותו לבנים 1 ועץ 1. קטע דרך יכול להיות מחובר רק ליישוב (או עיר) בבעלות השחקן או לקטע דרך נוסף. 2. יישוב: עלות היישוב היא לבנה 1, עץ 1, צמר 1 ושיבולת 1. ניתן לבנות יישוב על צומת שאליה מובילה דרך אחת לפחות ומברחק של 2 קטעי דרך מיישוב אחר. בניית יישוב מקנה לשחקן נקודת ניצחון אחת. 3. עיר: עיר יכולה להחליף יישוב קיים. עלות הבנייה היא ברזל 3 ושיבולת 2. ברגע שמשדרגים יישוב לעיר, השחקן מאבד את הנקודה של היישוב ומקבל 2 נקודות על הבנייה. עיר מעניקה לשחקן פי-2 יותר משאבים מכל חבלי הארץ הסמוכים לה.
    משאבים: כאמור, המשאבים מתקבלים מחבלי הארץ השונים. כאשר שחקן מטיל את קוביות המשחק, כל השחקנים מקבלים משאבים בהתאם למספר שיצא בהטלה (כלומר אם יצא 3 בהטלה, אז שחקנים עם יישובים/ערים הגובלים עם חבלי ארץ בעלי אותו מספר זוכים במשאב).
    מסחר: שחקנים יכולים לבצע מסחר ביניהם (כלומר להחליף משאבים) בהתאם לאיך שהם קובעים.

__מהלך המשחק__

כל שחקן מתחיל את המשחק עם 2 יישובים ו-2 קטעי דרך המעניקים לו 2 נקודות ניצחון. בנוסף, השחקנים מקבלים משאבים התחלתיים בהתאם למקומות שבהם הם מיקמו את היישובים (משאב אחד מכל משאב אפשרי). סדר המשחק הוא לפי מספור השחקנים(1,2,3). בכל תור השחקנים מטילים 2 קוביות. בהתאם לתוצאת ההטלה, השחקנים מקבלים משאבים כמו שפורט מקודם. שחקן בתור נתון עושה את הפעולות הבאות (לאחר הטלת הקוביות):
הוא יכול לסחור (כלומר להחליף  משאבים).
    הוא יכול לבנות דרכים, יישובים או ערים ויכול לקנות\לנצל קלפי פיתוח. אם סכום ההטלה הוא 7, על כל השחקנים בעלי יותר מ-7 קלפי משאבים לבחור מחצית מהקלפים ולהחזיר אותם לערימה.
__סיום המשחק__

המשחק מסתיים בתור שבו אחד השחקנים הגיע ל-10 או יותר נקודות ניצחון. כדי לנצח במשחק, השחקן צריך שיגיע תורו ובאותו התור יהיו לו 10 נקודות לכל הפחות.

__מימוש המשחק__

לוח המשחק הינו לוח קבוע. (מצורף קובץ PDF עם תמונה של לוח המשחק הקבוע):

![image](https://github.com/RoniHarTuv/The-Settlers-of-Catan_Game/assets/149065885/a87e9aa8-182b-4540-a18e-cff0bdca87d9)

זריקת הקוביות מתבצעת בצורה רנדומלית וזה מה שקובע את מהלכו (הרנדומלי) המשחק. בקובץ demo.cpp ניתן לראות המחשה של כמה סבבים במשחק.
הערות:

כיוון שהמשחק רץ ללא התערבות השחקנים, קלף הפיתוח מונופול ייבחר בצורה אוטומטית לבקש את קלף המשאב ממנו יש לשחקן את הכמות הכי קטנה.
קלף הפיתוח בניית דרכים יעניק לשחקן שמממש אותו 2 קלפי עץ ו2 קלפי לבנים במטרה שיוכל לבנות איתם דרכים.
קלף הפיתוח שנת שפע יעניק לשחקן את 2 קלפי המשאבים מהם יש לו את הכמות הקטנה ביותר.

__מחלקות המשחק והיררכיה__

1. מחלקת Asset המייצגת את כלי המשחק. לכל כלי יש שחקן שהוא הבעלים של החלק. ממחלקה זו יורשות 3 מחלקות:
2. מחלקת Road המייצגת דרך.
3. מחלקת Settelment המייצגת יישוב.
4. מחלקת Town המייצגת עיר.
5. מחלקת Board המייצגת את לוח המשחק: לוח משחק מורכב מ19 חלקות אדמה הממוספרות מ2 עד 12, 54 צמתים עליהם ניתן להניח יישוב או עיר, ו72 שבילים עליהם ניתן להניח דרכים.
6. מחלקת Junction המייצגת "צומת". צומת יכולה להיות פנויה או תפוסה על ידי כלי משחק. לכל צומת יש שדה של חלקות אדמה עליהם הצומת יושבת(בשביל ששחקן יוכל לקבל משאבים מהאדמות עליהם התיישב), ושדה של דרכים היוצאות מהצומת הזו(על מנת שיוכלו לחבר בין ערים ע"י דרכים בצורה חוקית)
7. מחלקת Way המייצגת שביל עליו ניתן להניח קטע דרך. לכל שביל יש שדה המייצג את 2 הצמתים ממנה הדרך יוצאת ונכנסת, מספר סידורי, וכמו כן האם היא תפוסה או לא.
8. מחלקת Land המייצגת חלקת אדמה. לכל חלקת אדמה מספר(המייצג את הספרה היצאה באותיות), ומחרוזת המייצגת את שם המשאב של אותה חלקת אדמה. בהתאם לסוג המשאב שחקן יוכל לקבל קלף משאב מתאים. בנוסף לכל חלקת אדמה מערך של 6 צמתים השוכנות על אדמה זו.
9. מחלקת Card המייצגת קלף משאב. ממחלקה זו יורשות 5 מחלקות המשאבים השונות: קלף עץ, כותנה, שיבולים,לבנים וברזל. לחלקת האדמה מדבר אין משאב.
10. מחלקת developmentcard המייצגת קלף פיתוח. ממחלקה זו יורשות 5 מחלקות שונות המייצגות את הסוגים השונים של קלפי הפיתוח המצויינים לעיל.
11. מחלקת Catan המיצגת מחלקה שתפקידה לתכלל את מרכיבי המשחק- מי הם השחקנים, מהו לוח המשחק, מתי המשחק מתחיל ומתי הוא נגמר.
12. מחלקת Player המייצגת שחקן. זו מחלקה עמוסת שדות ומטודות שכן לכל שחקן יש מגוון רחב של פעולות אותם הוא יכול לבצע. כל שחקן בתורו זורק את הקוביה קודם כל ורק לאחר מכן יכול לבצע פעולות כרצונו. אין הגבלה על כמות הפעולות ששחקן בוחר לעשות בכל תור,ואין חשיבות לסדר הפעולות. *הערה: פירוט על אופן המטודות נמצא בשורות הקוד.
13. מחלקת PlayerForTest מחלקה זו יורשת ממחלקת Player.מחלקה זו נוצרה על מנת להוסיף פונקציונליות למחלקת Player ע"מ שנוכל לבצע טסטים על המשחק. לcatan אין גישה למחלקה זו ולכן הלקוח לא יוכל להשתמש במחלקה זו.
14. מחלקת Demo המדגימה 9 סיבובים ובהם כל הפעולות ששחקנים יכולים לבצע.
15. קובץ MAKE FILE בעת הרצת make catan ירוץ קובץ המדמה סיבובי משחק .
16. קובץ טסטים.

__ספריות__

במימוש נעשה שימוש עיקרי בספריות הבאות:  vector random map string iostream

להלן פלט הרצת valgrind על קובץ הdemo:
![image](https://github.com/RoniHarTuv/The-Settlers-of-Catan_Game/assets/149065885/55f56992-d864-4889-9c9b-ff100fe8bea8)






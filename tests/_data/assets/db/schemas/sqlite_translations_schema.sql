PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;

CREATE TABLE `languagei18n` (
	`from_lang`	TEXT NOT NULL,
	`from_locale`	TEXT NOT NULL,
	`lang`	TEXT NOT NULL,
	`locale`	TEXT NOT NULL
);

INSERT INTO `languagei18n` (from_lang,from_locale,lang,locale) VALUES
 ('English','en-au','English','Australia'),
 ('English','en-bz','English','Belize'),
 ('English','en-ca','English','Canada'),
 ('Dutch','nl-be','Dutch','Belgium-1'),
 ('Dutch','nl-nl','Dutch','Netherlands'),
 ('Dutch','nl-be','Dutch','Belgium-2');

CREATE TABLE "language" (
	`lang`	TEXT NOT NULL,
	`locale`	TEXT NOT NULL
);

INSERT INTO `language` (lang,locale) VALUES
 ('Dutch','nl-be'),
 ('Dutch','nl-nl'),
 ('English','en-au'),
 ('English','en-bz'),
 ('English','en-ca');

COMMIT;

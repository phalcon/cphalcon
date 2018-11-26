<?php

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset\Simple;

/**
 * Phalcon\Test\Models\Language
 *
 * @property string lang
 * @property string locale
 * @property Simple translations
 * @method Simple getTranslations()
 *
 * @package Phalcon\Test\Models
 */
class Language extends Model
{
    public function getSource()
    {
        return 'language';
    }

    public function initialize()
    {
        $this->hasMany(
            ['lang', 'locale'],
            LanguageI18n::class,
            ['from_lang', 'from_locale'],
            ['alias' => 'translations']
        );
    }
}

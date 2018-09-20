<?php

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

/**
 * Phalcon\Test\Models\LanguageI18n
 *
 * @property string from_lang
 * @property string from_locale
 * @property string lang
 * @property string locale
 *
 * @package Phalcon\Test\Models
 */
class LanguageI18n extends Model
{
    public function getSource()
    {
        return 'languagei18n';
    }

    public function initialize()
    {
        $this->belongsTo(
            ['from_lang', 'from_lang'],
            Language::class,
            ['lang', 'locale'],
            ['alias' => 'Origin']
        );

        $this->belongsTo(
            ['lang', 'locale'],
            Language::class,
            ['lang', 'locale'],
            ['alias' => 'Target']
        );
    }
}

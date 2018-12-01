<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

/**
 * @property string from_lang
 * @property string from_locale
 * @property string lang
 * @property string locale
 *
 * @package Phalcon\Test\Models
 */
class LanguageI18n extends Model
{
    public function getSource(): string
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

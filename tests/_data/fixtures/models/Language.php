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
use Phalcon\Mvc\Model\Resultset\Simple;

/**
 * @property string lang
 * @property string locale
 * @property Simple translations
 * @method Simple getTranslations()
 * @package Phalcon\Test\Models
 */
class Language extends Model
{
    public function getSource(): string
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

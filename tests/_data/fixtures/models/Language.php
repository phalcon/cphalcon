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

use Phalcon\Mvc\Model\AbstractModel;
use Phalcon\Mvc\Model\Resultset\Simple;

/**
 * @property string lang
 * @property string locale
 * @property Simple translations
 * @method Simple getTranslations()
 */
class Language extends AbstractModel
{
    public function initialize()
    {
        $this->setSource('language');

        $this->hasMany(
            [
                'lang',
                'locale',
            ],
            LanguageI18n::class,
            [
                'from_lang',
                'from_locale',
            ],
            [
                'alias' => 'translations',
            ]
        );
    }
}

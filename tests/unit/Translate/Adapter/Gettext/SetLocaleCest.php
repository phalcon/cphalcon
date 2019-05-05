<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Translate\Adapter\Gettext;

use UnitTester;

class SetLocaleCest
{
    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: setLocale()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterGettextSetLocale(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Gettext - setLocale()');

        $I->skipTest('Need implementation');
    }
}

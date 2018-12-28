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

/**
 * Class TCest
 */
class TCest
{
    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: t()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterGettextT(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Gettext - t()');
        $I->skipTest('Need implementation');
    }
}

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

namespace Phalcon\Test\Unit\Tag;

use UnitTester;

class FormCest
{
    /**
     * Tests Phalcon\Tag :: form()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function tagForm(UnitTester $I)
    {
        $I->wantToTest('Tag - form()');

        $I->skipTest('Need implementation');
    }
}

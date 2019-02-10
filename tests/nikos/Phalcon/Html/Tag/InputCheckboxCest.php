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

namespace Phalcon\Test\Unit\Html\Tag;

use UnitTester;

/**
 * Class InputCheckboxCest
 */
class InputCheckboxCest
{
    /**
     * Tests Phalcon\Html\Tag :: inputCheckbox()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function htmlTagInputCheckbox(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - inputCheckbox()');
        $I->skipTest('Need implementation');
    }
}

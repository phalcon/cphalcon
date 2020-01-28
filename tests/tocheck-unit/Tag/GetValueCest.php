<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Tag;

use UnitTester;

class GetValueCest
{
    /**
     * Tests Phalcon\Tag :: getValue()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function tagGetValue(UnitTester $I)
    {
        $I->wantToTest('Tag - getValue()');
        $I->skipTest('Need implementation');
    }
}

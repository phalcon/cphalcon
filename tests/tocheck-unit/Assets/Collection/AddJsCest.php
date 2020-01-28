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

namespace Phalcon\Test\Unit\Assets\Collection;

use UnitTester;

class AddJsCest
{
    /**
     * Tests Phalcon\Assets\Collection :: addJs()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsCollectionAddJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - addJs()');

        $I->skipTest('Need implementation');
    }
}

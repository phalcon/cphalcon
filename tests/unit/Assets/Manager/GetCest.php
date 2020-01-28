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

namespace Phalcon\Test\Unit\Assets\Manager;

use Phalcon\Assets\Exception;
use Phalcon\Assets\Manager;
use UnitTester;

class GetCest
{
    /**
     * Tests Phalcon\Assets\Manager :: get() - unknown
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-06-04
     */
    public function assetsManagerGetUnknown(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - get() - unknown');

        $I->expectThrowable(
            new Exception('The collection does not exist in the manager'),
            function () {
                $assets = new Manager();

                $assets->get('some-non-existent-collection');
            }
        );
    }
}

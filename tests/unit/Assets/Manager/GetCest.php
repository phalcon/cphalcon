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

namespace Phalcon\Test\Unit\Assets\Manager;

use Phalcon\Assets\Exception;
use Phalcon\Assets\Manager;
use UnitTester;

/**
 * Class GetCest
 */
class GetCest
{
    /**
     * Tests Phalcon\Assets\Manager :: get() - unknown
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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

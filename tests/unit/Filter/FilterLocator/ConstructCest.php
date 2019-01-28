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

namespace Phalcon\Test\Unit\Filter\Locator;

use Phalcon\Filter\FilterLocator;
use Phalcon\Service\Exception;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Filter\Locator :: __construct() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-01-19
     */
    public function filterFilterLocatorConstruct(UnitTester $I)
    {
        $I->wantToTest('Filter\FilterLocator - __construct() - empty');
        $I->expectThrowable(
            new Exception('The service unknown has not been found in the locator'),
            function () {
                $locator = new FilterLocator();
                $locator->get('unknown');
            }
        );
    }
}

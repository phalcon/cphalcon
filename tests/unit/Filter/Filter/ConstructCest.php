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

namespace Phalcon\Tests\Unit\Filter\Filter;

use Phalcon\Filter;
use Phalcon\Filter\Exception;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Filter\Locator :: __construct() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function filterFilterConstruct(UnitTester $I)
    {
        $I->wantToTest('Filter\Filter - __construct() - empty');
        $I->expectThrowable(
            new Exception('The service unknown has not been found in the locator'),
            function () {
                $locator = new Filter();
                $locator->get('unknown');
            }
        );
    }
}

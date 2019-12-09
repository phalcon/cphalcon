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

namespace Phalcon\Test\Integration\Forms\Element\Select;

use IntegrationTester;

/**
 * Class AddFilterCest
 */
class AddFilterCest
{
    /**
     * Tests Phalcon\Forms\Element\Select :: addFilter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsElementSelectAddFilter(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Select - addFilter()');
        $I->skipTest('Need implementation');
    }
}

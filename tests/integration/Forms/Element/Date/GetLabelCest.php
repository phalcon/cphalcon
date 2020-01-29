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

namespace Phalcon\Test\Integration\Forms\Element\Date;

use IntegrationTester;

/**
 * Class GetLabelCest
 */
class GetLabelCest
{
    /**
     * Tests Phalcon\Forms\Element\Date :: getLabel()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsElementDateGetLabel(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Date - getLabel()');
        $I->skipTest('Need implementation');
    }
}

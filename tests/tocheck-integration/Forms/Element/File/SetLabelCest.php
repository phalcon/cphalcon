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

namespace Phalcon\Test\Integration\Forms\Element\File;

use IntegrationTester;

/**
 * Class SetLabelCest
 */
class SetLabelCest
{
    /**
     * Tests Phalcon\Forms\Element\File :: setLabel()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsElementFileSetLabel(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\File - setLabel()');
        $I->skipTest('Need implementation');
    }
}

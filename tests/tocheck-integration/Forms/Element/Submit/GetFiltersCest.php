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

namespace Phalcon\Test\Integration\Forms\Element\Submit;

use IntegrationTester;

/**
 * Class GetFiltersCest
 */
class GetFiltersCest
{
    /**
     * Tests Phalcon\Forms\Element\Submit :: getFilters()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsElementSubmitGetFilters(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Submit - getFilters()');
        $I->skipTest('Need implementation');
    }
}

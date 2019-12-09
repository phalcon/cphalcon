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
 * Class SetUserOptionsCest
 */
class SetUserOptionsCest
{
    /**
     * Tests Phalcon\Forms\Element\Select :: setUserOptions()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsElementSelectSetUserOptions(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Select - setUserOptions()');
        $I->skipTest('Need implementation');
    }
}

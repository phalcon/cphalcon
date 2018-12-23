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

namespace Phalcon\Test\Integration\Forms\Element\Check;

use IntegrationTester;

/**
 * Class SetAttributeCest
 */
class SetAttributeCest
{
    /**
     * Tests Phalcon\Forms\Element\Check :: setAttribute()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementCheckSetAttribute(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Check - setAttribute()');
        $I->skipTest('Need implementation');
    }
}

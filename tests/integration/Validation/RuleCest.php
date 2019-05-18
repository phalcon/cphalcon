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

namespace Phalcon\Test\Integration\Validation;

use IntegrationTester;

/**
 * Class RuleCest
 */
class RuleCest
{
    /**
     * Tests Phalcon\Validation :: rule()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-16
     */
    public function validationRule(IntegrationTester $I)
    {
        $I->wantToTest('Validation - rule()');

        $I->skipTest('Need implementation');
    }
}

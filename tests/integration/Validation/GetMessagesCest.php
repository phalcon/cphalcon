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
 * Class GetMessagesCest
 */
class GetMessagesCest
{
    /**
     * Tests Phalcon\Validation :: getMessages()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-16
     */
    public function validationGetMessages(IntegrationTester $I)
    {
        $I->wantToTest('Validation - getMessages()');

        $I->skipTest('Need implementation');
    }
}

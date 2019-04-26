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
use Phalcon\Test\Models\Users;
use Phalcon\Validation;

/**
 * Class GetEntityCest
 */
class GetEntityCest
{
    /**
     * Tests Phalcon\Validation :: getEntity()
     *
     * @param IntegrationTester $I
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-17
     */
    public function validationGetEntity(IntegrationTester $I)
    {
        $I->wantToTest('Validation - getEntity()');

        $user = new \stdClass();

        $validation = new Validation();

        $validation->setEntity($user);

        $I->assertSame(
            $user,
            $validation->getEntity()
        );
    }
}

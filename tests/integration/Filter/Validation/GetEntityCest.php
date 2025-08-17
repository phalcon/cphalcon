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

namespace Phalcon\Tests\Integration\Filter\Validation;

use IntegrationTester;
use Phalcon\Filter\Validation;
use stdClass;

class GetEntityCest
{
    /**
     * Tests Phalcon\Filter\Validation :: getEntity()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     */
    public function filterValidationGetEntity(IntegrationTester $I): void
    {
        $I->wantToTest('Validation - getEntity()');

        $user = new stdClass();

        $validation = new Validation();

        $validation->setEntity($user);

        $I->assertSame(
            $user,
            $validation->getEntity()
        );
    }

    /**
     * Tests Phalcon\Filter\Validation :: getEntity() - with filters
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-08-12
     */
    public function filterValidationGetEntityWithFilters(IntegrationTester $I): void
    {
        $I->wantToTest('Validation - getEntity() - with filters');

        $user       = new stdClass();
        $user->name = '';

        $validation = new Validation();
        $validation->setFilters('name', ['trim', 'striptags']);
        $validation->validate(['name' => ' John <script>Chris</script>'], $user);

        $I->assertSame(
            'John Chris',
            $validation->getEntity()->name
        );

        $I->assertSame(
            'John Chris',
            $validation->getValue('name')
        );
    }

    /**
     * Tests Phalcon\Filter\Validation :: getEntity() - using bind() with whitelist fields
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-08-12
     */
    public function filterValidationGetEntityUsingBindWithWhitelistFields(IntegrationTester $I): void
    {
        $I->wantToTest('Validation - getEntity() - using bind() with whitelist fields');

        $user           = new stdClass();
        $user->name     = '';
        $user->email    = '';
        $user->password = '';

        $postData = [
            'name'     => 'John Doe',
            'email'    => 'name@example.com',
            'password' => 'new_password'
        ];

        $validation = new Validation();
        $validation
            ->bind($user, $postData, ['name', 'password'])
            ->validate();

        $I->assertSame('John Doe', $validation->getEntity()->name);
        $I->assertSame('John Doe', $validation->getValue('name'));

        $I->assertSame('', $validation->getEntity()->email);
        $I->assertSame('', $validation->getValue('email'));

        $I->assertSame('new_password', $validation->getEntity()->password);
        $I->assertSame('new_password', $validation->getValue('password'));
    }

    /**
     * Tests Phalcon\Filter\Validation :: getEntity() - using validate() with whitelist fields
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-08-12
     */
    public function filterValidationGetEntityUsingValidateWithWhitelistFields(IntegrationTester $I): void
    {
        $I->wantToTest('Validation - getEntity() - using validate() with whitelist fields');

        $user           = new stdClass();
        $user->name     = '';
        $user->email    = '';
        $user->password = '';

        $postData = [
            'name'     => 'John Doe',
            'email'    => 'name@example.com',
            'password' => 'new_password'
        ];

        $validation = new Validation();
        $validation->validate($postData, $user, ['name', 'password']);

        $I->assertSame('John Doe', $validation->getEntity()->name);
        $I->assertSame('John Doe', $validation->getValue('name'));

        $I->assertSame('', $validation->getEntity()->email);
        $I->assertSame('', $validation->getValue('email'));

        $I->assertSame('new_password', $validation->getEntity()->password);
        $I->assertSame('new_password', $validation->getValue('password'));
    }
}

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

namespace Phalcon\Test\Integration\Validation;

use IntegrationTester;
use Phalcon\Validation;
use stdClass;

class BindCest
{
    /**
     * Tests Phalcon\Validation :: bind()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     */
    public function validationBind(IntegrationTester $I)
    {
        $I->wantToTest('Validation - bind()');

        $user = new stdClass();

        $data = [
            'name' => 'Sid',
            'city' => 'Busan',
        ];

        $validation = new Validation();

        $validation->bind($user, $data);

        $I->assertSame(
            $user,
            $validation->getEntity()
        );

        $I->assertSame(
            $data,
            $validation->getData()
        );
    }
}

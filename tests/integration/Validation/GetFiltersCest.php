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
use Phalcon\Validation\Validation;
use Phalcon\Validation\Validator\PresenceOf;

class GetFiltersCest
{
    /**
     * Tests Phalcon\Validation\Validation :: getFilters()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-27
     */
    public function validationGetFilters(IntegrationTester $I)
    {
        $I->wantToTest('Validation - getFilters()');

        $validation = new Validation();

        $validation->add(
            'name',
            new PresenceOf()
        );

        $validation->add(
            'email',
            new PresenceOf()
        );

        $validation->setFilters('name', 'trim');
        $validation->setFilters('email', 'lower');

        $I->assertEquals(
            [
                'name'  => 'trim',
                'email' => 'lower',
            ],
            $validation->getFilters()
        );
    }
}

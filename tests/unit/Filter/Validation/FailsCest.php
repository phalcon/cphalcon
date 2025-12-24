<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Tests\Unit\Filter\Validation;

use Phalcon\Filter\Validation;
use UnitTester;

class FailsCest
{
    /**
     * Tests Phalcon\Filter\Validation :: fails()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-08-02
     */
    public function testfailsTrue(UnitTester $I)
    {
        $I->wantToTest('Phalcon\Filter\Validation :: fails() - true');

        $validation = new Validation();
        $validation->add('email', new Validation\Validator\Email());
        $I->assertNotEmpty($validation->validate(['email' => 'test@-example.com']));
        $I->assertTrue($validation->fails());
    }

    /**
     * Tests Phalcon\Filter\Validation :: fails() - false
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-08-02
     */
    public function testfailsFalse(UnitTester $I)
    {
        $I->wantToTest('Phalcon\Filter\Validation :: fails() - false');

        $validation = new Validation();
        $validation->add('email', new Validation\Validator\Email());
        $I->assertEmpty($validation->validate(['email' => 'test@example.com']));
        $I->assertFalse($validation->fails());
    }
}

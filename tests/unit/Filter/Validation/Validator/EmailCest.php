<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Filter\Validation\Validator;

use Phalcon\Filter\Validation;
use UnitTester;

class EmailCest
{
    /**
     * Tests Filter\Validation\Validator\Email :: validate
     *
     * @param UnitTester $I
     *
     * @author n[oO]ne <lominum@protonmail.com>
     * @since  2024-08-19
     */
    public function validEmail(UnitTester $I)
    {
        $I->wantToTest('Filter\Validation\Validator\Email - valid email');

        $validation = new Validation();
        $validation->add('email', new Validation\Validator\Email());
        $I->assertEmpty($validation->validate(['email' => 'test@example.com']));
    }

    /**
     * Tests Filter\Validation\Validator\Email :: validate
     *
     * @param UnitTester $I
     *
     * @author n[oO]ne <lominum@protonmail.com>
     * @since  2024-08-19
     */
    public function invalidEmail(UnitTester $I)
    {
        $I->wantToTest('Filter\Validation\Validator\Email - invalid email');

        $validation = new Validation();
        $validation->add('email', new Validation\Validator\Email());
        $I->assertNotEmpty($validation->validate(['email' => 'test@-example.com']));
    }

    /**
     * Tests Filter\Validation\Validator\Email :: validate
     *
     * @param UnitTester $I
     *
     * @author n[oO]ne <lominum@protonmail.com>
     * @since  2024-08-19
     */
    public function emailWithoutUTF8Success(UnitTester $I)
    {
        $I->wantToTest('Filter\Validation\Validator\Email - without utf8 is ok');

        $validation = new Validation();
        $validation->add('email', new Validation\Validator\Email());
        $I->assertEmpty($validation->validate(['email' => 'test@example.com']));
    }

    /**
     * Tests Filter\Validation\Validator\Email :: validate
     *
     * @param UnitTester $I
     *
     * @author n[oO]ne <lominum@protonmail.com>
     * @since  2024-08-19
     */
    public function emailAllowEmptyFails(UnitTester $I)
    {
        $I->wantToTest('Filter\Validation\Validator\Email - empty is not ok');

        $validation = new Validation();
        $validation->add('email', new Validation\Validator\Email());
        $I->assertNotEmpty($validation->validate(['email' => '']));
    }

    /**
     * Tests Filter\Validation\Validator\Email :: validate
     *
     * @param UnitTester $I
     *
     * @author n[oO]ne <lominum@protonmail.com>
     * @since  2024-08-19
     */
    public function emailAllowEmptySuccess(UnitTester $I)
    {
        $I->wantToTest('Filter\Validation\Validator\Email - empty is ok');

        $validation = new Validation();
        $validation->add('email', new Validation\Validator\Email(['allowEmpty' => true]));
        $I->assertEmpty($validation->validate(['email' => '']));
    }

    /**
     * Tests Filter\Validation\Validator\Email :: validate
     *
     * @param UnitTester $I
     *
     * @author n[oO]ne <lominum@protonmail.com>
     * @since  2024-08-19
     */
    public function emailWithUTF8Fail(UnitTester $I)
    {
        $I->wantToTest('Filter\Validation\Validator\Email - with utf8 fails');

        $validation = new Validation();
        $validation->add('email', new Validation\Validator\Email());
        $I->assertNotEmpty($validation->validate(['email' => 'täst@example.com']));
    }

    /**
     * Tests Filter\Validation\Validator\Email :: validate
     *
     * @param UnitTester $I
     *
     * @author n[oO]ne <lominum@protonmail.com>
     * @since  2024-08-19
     */
    public function emailWithUTF8Success(UnitTester $I)
    {
        $I->wantToTest('Filter\Validation\Validator\Email - with utf8 success');

        $validation = new Validation();
        $validation->add('email', new Validation\Validator\Email(['allowUTF8' => true]));
        $I->assertEmpty($validation->validate(['email' => 'täst@example.com']));
    }
}

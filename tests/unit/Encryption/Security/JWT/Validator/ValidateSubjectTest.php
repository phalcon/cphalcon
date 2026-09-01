<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Validator;

use Phalcon\Encryption\Security\JWT\Validator;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Encryption\Fake\JWTTrait;

final class ValidateSubjectTest extends AbstractUnitTestCase
{
    use JWTTrait;

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17361
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-15
     */
    public function testEncryptionSecurityJWTValidatorValidateSubject(): void
    {
        $token     = $this->newToken();
        $validator = new Validator($token);
        $this->assertInstanceOf(Validator::class, $validator);

        $validator->validateSubject("unknown");

        $expected = ["Validation: incorrect subject"];
        $actual   = $validator->getErrors();
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests that a null subject expresses no expectation and is skipped.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17361
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-15
     */
    public function testEncryptionSecurityJWTValidatorValidateSubjectNull(): void
    {
        $token     = $this->newToken();
        $validator = new Validator($token);

        $validator->validateSubject(null);

        $expected = [];
        $actual   = $validator->getErrors();
        $this->assertSame($expected, $actual);
    }
}

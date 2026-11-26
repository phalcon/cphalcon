<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption;

use Phalcon\Encryption\Security\JWT\Validator;
use Phalcon\Encryption\Security\Random;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Encryption\Fake\JWTTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\IgnoreDeprecations;
use TypeError;

use function strlen;

/**
 * cphalcon accepts a value of any type for these parameters. The method body
 * examines the value.
 *
 * @issue https://github.com/phalcon/phalcon/issues/850
 */
final class ParameterTypesTest extends AbstractUnitTestCase
{
    use JWTTrait;

    /**
     * @return array<string, array{0: mixed, 1: int}>
     */
    public static function getNumbers(): array
    {
        return [
            'string' => ['10', 10],
            'true'   => [true, 1],
            'false'  => [false, 16],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/850
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testEncryptionSecurityJWTValidatorValidateClaim(): void
    {
        $validator = new Validator($this->newToken());

        $validator->validateClaim('unknown', null);
        $this->assertSame([], $validator->getErrors());

        $validator->validateClaim('uid', [456]);
        $this->assertSame(['Validation: incorrect uid'], $validator->getErrors());
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/850
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getNumbers')]
    public function testEncryptionSecurityRandomBase(mixed $number, int $expected): void
    {
        $this->assertSame($expected, strlen($this->getRandom()->call($number)));
    }

    /**
     * cphalcon gives the deprecation "Passing null to parameter #1 ($len) of
     * type int" for a null number.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/850
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[IgnoreDeprecations]
    public function testEncryptionSecurityRandomBaseNull(): void
    {
        $this->assertSame(16, strlen($this->getRandom()->call(null)));
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/850
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testEncryptionSecurityRandomBaseString(): void
    {
        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'Phalcon\\Encryption\\Security\\Random::bytes(): Argument #1 ($len) '
            . 'must be of type int, string given'
        );

        $this->getRandom()->call('abc');
    }

    private function getRandom(): Random
    {
        return new class () extends Random {
            public function call(mixed $number): string
            {
                return $this->base(
                    'abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ-_',
                    64,
                    $number
                );
            }
        };
    }
}

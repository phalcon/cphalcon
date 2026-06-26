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

namespace Phalcon\Tests\Unit\Auth;

use Phalcon\Auth\Exception;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class ExceptionHierarchyTest extends AbstractUnitTestCase
{
    /**
     * @return array<int, array{0: class-string}>
     */
    public static function exceptionProvider(): array
    {
        return [
            [\Phalcon\Auth\Exceptions\AccessDenied::class],
            [\Phalcon\Auth\Exceptions\AccessNotRegistered::class],
            [\Phalcon\Auth\Exceptions\ActiveAccessRequired::class],
            [\Phalcon\Auth\Exceptions\ConfigRequiresNonEmptyValue::class],
            [\Phalcon\Auth\Exceptions\DataMustContainIdKey::class],
            [\Phalcon\Auth\Exceptions\DefaultGuardNotRegistered::class],
            [\Phalcon\Auth\Exceptions\DoesNotImplement::class],
            [\Phalcon\Auth\Exceptions\FileCannotRead::class],
            [\Phalcon\Auth\Exceptions\FileDoesNotContainJson::class],
            [\Phalcon\Auth\Exceptions\FileDoesNotExist::class],
            [\Phalcon\Auth\Exceptions\FileNotValidJson::class],
            [\Phalcon\Auth\Exceptions\GuardNotDefined::class],
            [\Phalcon\Auth\Exceptions\MissingHandlerContext::class],
            [\Phalcon\Auth\Exceptions\OptionRequiresArray::class],
            [\Phalcon\Auth\Exceptions\OptionRequiresString::class],
            [\Phalcon\Auth\Exceptions\SessionNamesMustDiffer::class],
            [\Phalcon\Auth\Exceptions\UnknownAdapter::class],
            [\Phalcon\Auth\Exceptions\UnknownGuard::class],
        ];
    }

    /**
     * Every granular Auth exception must extend Phalcon\Auth\Exception, so
     * existing `catch (Phalcon\Auth\Exception)` blocks keep working.
     *
     * @param class-string $exceptionClass
     */
    #[DataProvider('exceptionProvider')]
    public function testExtendsAuthException(string $exceptionClass): void
    {
        $this->assertTrue(
            is_subclass_of($exceptionClass, Exception::class),
            $exceptionClass . ' must extend ' . Exception::class
        );
    }
}

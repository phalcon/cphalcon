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

namespace Phalcon\Tests\Unit\Storage;

use Phalcon\Storage\Serializer\Php;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use stdClass;
use TypeError;

use function serialize;

/**
 * cphalcon accepts a value of any type for these parameters. The method body
 * examines the value.
 *
 * @issue https://github.com/phalcon/phalcon/issues/850
 */
final class ParameterTypesTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array{0: mixed, 1: string}>
     */
    public static function getAllowedClasses(): array
    {
        return [
            'null'   => [null, 'null'],
            'string' => ['10', 'string'],
        ];
    }

    /**
     * The value is stored as it is. unserialize() then gives the TypeError
     * for the "allowed_classes" option, as in cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/850
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getAllowedClasses')]
    public function testStorageSerializerPhpSetAllowedClasses(mixed $allowedClasses, string $type): void
    {
        $serializer = new Php();
        $serializer->setAllowedClasses($allowedClasses);

        $this->assertSame($allowedClasses, $serializer->getAllowedClasses());

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'unserialize(): Option "allowed_classes" must be of type array|bool, '
            . $type . ' given'
        );

        $serializer->unserialize(serialize(new stdClass()));
    }
}

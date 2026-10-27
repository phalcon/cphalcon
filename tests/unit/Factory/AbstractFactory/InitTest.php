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

namespace Phalcon\Tests\Unit\Factory\AbstractFactory;

use Phalcon\Factory\AbstractFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use stdClass;

final class InitTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array{0: array<array-key, string>, 1: array<array-key, string>}>
     */
    public static function getInitCases(): array
    {
        return [
            'no services'     => [
                [],
                ['one' => 'ClassOne', 'two' => 'ClassTwo'],
            ],
            'replace and add' => [
                ['two' => 'ClassNew', 'three' => 'ClassThree'],
                ['one' => 'ClassOne', 'two' => 'ClassNew', 'three' => 'ClassThree'],
            ],
            'integer key'     => [
                [5 => 'ClassFive'],
                ['one' => 'ClassOne', 'two' => 'ClassTwo', 0 => 'ClassFive'],
            ],
        ];
    }

    /**
     * init() sets the default services and the custom services in the
     * mapper. A custom service replaces a default service with the same
     * name.
     *
     * @param array<array-key, string> $services
     * @param array<array-key, string> $expected
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-27
     */
    #[DataProvider('getInitCases')]
    public function testFactoryAbstractFactoryInit(array $services, array $expected): void
    {
        $factory = $this->getFactory();

        $this->callProtectedMethod($factory, 'init', $services);

        $actual = $this->getProtectedProperty($factory, 'mapper');
        $this->assertSame($expected, $actual);
    }

    /**
     * A second init() keeps the order of the mapper: a name that exists
     * keeps its place, a new name goes at the end.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-27
     */
    public function testFactoryAbstractFactoryInitAgain(): void
    {
        $factory = $this->getFactory();

        $this->callProtectedMethod($factory, 'init', ['three' => 'ClassThree']);
        $this->callProtectedMethod($factory, 'init', ['four' => 'ClassFour', 'one' => 'ClassNew']);

        $expected = [
            'one'   => 'ClassNew',
            'two'   => 'ClassTwo',
            'three' => 'ClassThree',
            'four'  => 'ClassFour',
        ];
        $actual   = $this->getProtectedProperty($factory, 'mapper');
        $this->assertSame($expected, $actual);
    }

    /**
     * init() removes the stored instances of the names that it sets. The
     * other instances stay, in their order.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-27
     */
    public function testFactoryAbstractFactoryInitServices(): void
    {
        $five    = new stdClass();
        $one     = new stdClass();
        $seven   = new stdClass();
        $six     = new stdClass();
        $factory = $this->getFactory();

        $this->setProtectedProperty(
            $factory,
            'services',
            ['five' => $five, 'one' => $one, 'six' => $six, 'seven' => $seven]
        );
        $this->callProtectedMethod($factory, 'init', ['seven' => 'ClassSeven']);

        $expected = ['five' => $five, 'six' => $six];
        $actual   = $this->getProtectedProperty($factory, 'services');
        $this->assertSame($expected, $actual);
    }

    private function getFactory(): AbstractFactory
    {
        return new class () extends AbstractFactory {
            protected function getServices(): array
            {
                return ['one' => 'ClassOne', 'two' => 'ClassTwo'];
            }
        };
    }
}

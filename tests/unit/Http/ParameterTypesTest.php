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

namespace Phalcon\Tests\Unit\Http;

use Error;
use Phalcon\Http\Request\Bag\AttributeBag;
use Phalcon\Http\Response;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;
use PHPUnit\Framework\Attributes\DataProvider;
use stdClass;
use TypeError;

/**
 * cphalcon accepts a value of any type for these parameters. The method body
 * examines the value.
 *
 * @issue https://github.com/phalcon/phalcon/issues/844
 */
final class ParameterTypesTest extends AbstractHttpBase
{
    private const ITEMS = [
        ''    => 'empty',
        5     => 'five',
        '5.5' => 'float',
        1     => 'one',
        'a'   => 'A',
    ];

    private const NOT_STRING = 'Object of class stdClass could not be converted to string';

    /**
     * @return array<string, array{0: mixed}>
     */
    public static function getAttachmentNames(): array
    {
        return [
            'null'   => [null],
            'int'    => [5],
            'false'  => [false],
            'array'  => [['a']],
            'object' => [new stdClass()],
        ];
    }

    /**
     * @return array<string, array{0: string, 1: mixed, 2: mixed}>
     */
    public static function getBagReaders(): array
    {
        return [
            'get null'        => ['get', null, 'empty'],
            'get float'       => ['get', 5.5, 'float'],
            'getArray null'   => ['getArray', null, []],
            'getArray float'  => ['getArray', 5.5, []],
            'getBool null'    => ['getBool', null, true],
            'getBool float'   => ['getBool', 5.5, true],
            'getFloat null'   => ['getFloat', null, 0.0],
            'getFloat float'  => ['getFloat', 5.5, 0.0],
            'getInt null'     => ['getInt', null, 0],
            'getInt float'    => ['getInt', 5.5, 0],
            'getString null'  => ['getString', null, 'empty'],
            'getString float' => ['getString', 5.5, 'float'],
            'has null'        => ['has', null, true],
            'has float'       => ['has', 5.5, true],
        ];
    }

    /**
     * @return array<string, array{0: mixed, 1: array<array-key, string>}>
     */
    public static function getBagRemoveKeys(): array
    {
        return [
            'null'  => [null, [5 => 'five', '5.5' => 'float', 1 => 'one', 'a' => 'A']],
            'float' => [5.5, ['' => 'empty', 5 => 'five', 1 => 'one', 'a' => 'A']],
        ];
    }

    /**
     * @return array<string, array{0: mixed, 1: array<array-key, string>}>
     */
    public static function getBagSetKeys(): array
    {
        return [
            'null'  => [null, ['' => 'x']],
            'float' => [5.5, ['5.5' => 'x']],
        ];
    }

    /**
     * @return array<string, array{0: mixed, 1: mixed, 2: array{0: int|null, 1: string|null}}>
     */
    public static function getConstructValues(): array
    {
        return [
            'code null'   => [null, null, [null, null]],
            'code string' => ['201', null, [201, 'Created']],
            'status null' => [200, null, [200, 'OK']],
            'status int'  => [200, 5, [200, '5']],
            'status true' => [200, true, [200, '1']],
        ];
    }

    /**
     * @return array<string, array{0: mixed, 1: string}>
     */
    public static function getRedirectLocations(): array
    {
        return [
            'null'        => [null, '/'],
            'false'       => [false, '/'],
            'int'         => [5, '/5'],
            'named route' => [['for' => 'about'], '/about'],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/844
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testHttpBagObjectKey(): void
    {
        $this->expectException(Error::class);
        $this->expectExceptionMessage(self::NOT_STRING);

        (new AttributeBag(self::ITEMS))->get(new stdClass());
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/844
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getBagReaders')]
    public function testHttpBagReaders(string $method, mixed $key, mixed $expected): void
    {
        $bag = new AttributeBag(self::ITEMS);

        $this->assertSame($expected, $bag->$method($key));
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/844
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     *
     * @param array<array-key, string> $expected
     */
    #[DataProvider('getBagRemoveKeys')]
    public function testHttpBagRemove(mixed $key, array $expected): void
    {
        $bag = new AttributeBag(self::ITEMS);
        $bag->remove($key);

        $this->assertSame($expected, $bag->all());
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/844
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     *
     * @param array<array-key, string> $expected
     */
    #[DataProvider('getBagSetKeys')]
    public function testHttpBagSet(mixed $key, array $expected): void
    {
        $bag = new AttributeBag();
        $bag->set($key, 'x');

        $this->assertSame($expected, $bag->all());
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/844
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     *
     * @param array{0: int|null, 1: string|null} $expected
     */
    #[DataProvider('getConstructValues')]
    public function testHttpResponseConstruct(mixed $code, mixed $status, array $expected): void
    {
        $response = new Response(null, $code, $status);

        $this->assertSame(
            $expected,
            [$response->getStatusCode(), $response->getReasonPhrase()]
        );
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/844
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testHttpResponseConstructCodeNotInt(): void
    {
        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'Phalcon\\Http\\Response::setStatusCode(): Argument #1 ($code) must be of type int, string given'
        );

        new Response(null, 'abc');
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/844
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testHttpResponseConstructStatusObject(): void
    {
        $this->expectException(Error::class);
        $this->expectExceptionMessage(self::NOT_STRING);

        new Response(null, 200, new stdClass());
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/844
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getRedirectLocations')]
    public function testHttpResponseRedirect(mixed $location, string $expected): void
    {
        $this->container->getShared('router')
            ->add('/about', ['controller' => 'about'])
            ->setName('about')
        ;
        $this->container->getShared('url')->setBaseUri('/');

        $response = $this->getResponseObject();
        $response->redirect($location);

        $this->assertSame($expected, $response->getHeaders()->get('Location'));
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/844
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getAttachmentNames')]
    public function testHttpResponseSetFileToSend(mixed $attachmentName): void
    {
        $response = new Response();
        $response->setFileToSend('path/to/file.txt', $attachmentName);

        $this->assertSame(
            [
                'Content-Description: File Transfer'                   => null,
                'Content-Type: application/octet-stream'               => null,
                'Content-Transfer-Encoding: binary'                    => null,
                'Content-Disposition: attachment; filename="file.txt"' => null,
            ],
            $response->getHeaders()->toArray()
        );
    }
}

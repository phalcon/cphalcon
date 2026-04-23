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

namespace Phalcon\Tests\Unit\Filter;

use Phalcon\Filter\FilterFactory;
use Phalcon\Tests\AbstractUnitTestCase;

use function call_user_func_array;
use function is_array;

final class SanitizeTest extends AbstractUnitTestCase
{
    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            /*[
                'absint',
                '',
                -125,
                125,
            ],
            [
                'absint',
                '',
                -125,
                125,
            ],
            [
                'absint',
                '',
                -125,
                125,
            ],
            [
                'absint',
                'absint',
                [-125],
                125,
            ],
            [
                'absint',
                'absint',
                [-125],
                125,
            ],
            [
                'absint',
                'absint',
                [-125],
                125,
            ],
            [
                'alnum',
                '',
                '0',
                '0',
            ],
            [
                'alnum',
                '',
                '',
                '',
            ],
            [
                'alnum',
                '',
                '?a&5xka\tŧ?1-s.Xa[\n',
                'a5xkat1sXan',
            ],
            [
                'alnum',
                'alnum',
                ['0'],
                '0',
            ],
            [
                'alnum',
                'alnum',
                [''],
                '',
            ],
            [
                'alnum',
                'alnum',
                ['?a&5xka\tŧ?1-s.Xa[\n'],
                'a5xkat1sXan',
            ],
            [
                'alpha',
                '',
                '0',
                '',
            ],
            [
                'alpha',
                '',
                '',
                '',
            ],
            [
                'alpha',
                '',
                '?a&5xka\tŧ?1-s.Xa[\n',
                'axkatsXan',
            ],
            [
                'alpha',
                'alpha',
                ['0'],
                '',
            ],
            [
                'alpha',
                'alpha',
                [''],
                '',
            ],
            [
                'alpha',
                'alpha',
                ['?a&5xka\tŧ?1-s.Xa[\n'],
                'axkatsXan',
            ],
            [
                'bool',
                '',
                1000,
                true,
            ],
            [
                'bool',
                '',
                0xFFA,
                true,
            ],
            [
                'bool',
                '',
                '1000',
                true,
            ],
            [
                'bool',
                '',
                null,
                false,
            ],
            [
                'bool',
                '',
                'on',
                true,
            ],
            [
                'bool',
                '',
                'off',
                false,
            ],
            [
                'bool',
                '',
                'yes',
                true,
            ],
            [
                'bool',
                '',
                'no',
                false,
            ],
            [
                'bool',
                '',
                'y',
                true,
            ],
            [
                'bool',
                '',
                'n',
                false,
            ],
            [
                'bool',
                '',
                0,
                false,
            ],
            [
                'bool',
                '',
                1,
                true,
            ],
            [
                'bool',
                'bool',
                [1000],
                true,
            ],
            [
                'bool',
                'bool',
                [0xFFA],
                true,
            ],
            [
                'bool',
                'bool',
                ['1000'],
                true,
            ],
            [
                'bool',
                'bool',
                [null],
                false,
            ],
            [
                'bool',
                'bool',
                ['on'],
                true,
            ],
            [
                'bool',
                'bool',
                ['off'],
                false,
            ],
            [
                'bool',
                'bool',
                ['yes'],
                true,
            ],
            [
                'bool',
                'bool',
                ['no'],
                false,
            ],
            [
                'bool',
                'bool',
                ['y'],
                true,
            ],
            [
                'bool',
                'bool',
                ['n'],
                false,
            ],
            [
                'bool',
                'bool',
                [1],
                true,
            ],
            [
                'bool',
                'bool',
                [0],
                false,
            ],
            [
                'email',
                '',
                "some(one)@exa\\mple.com",
                'someone@example.com',
            ],
            [
                'email',
                '',
                "!(first.guy)
                    @*my-domain**##.com.rx//",
                "!first.guy@*my-domain**##.com.rx",
            ],
            [
                'email',
                'email',
                ["some(one)@exa\\mple.com"],
                'someone@example.com',
            ],
            [
                'email',
                'email',
                [
                    "!(first.guy)
                    @*my-domain**##.com.rx//",
                ],
                "!first.guy@*my-domain**##.com.rx",
            ],
            [
                'float',
                '',
                '1000.01',
                1000.01,
            ],
            [
                'float',
                '',
                0xFFA,
                0xFFA,
            ],
            [
                'float',
                '',
                "lol",
                0.0,
            ],
            [
                'float',
                'float',
                ['1000.01'],
                1000.01,
            ],
            [
                'float',
                'float',
                [0xFFA],
                0xFFA,
            ],
            [
                'float',
                'float',
                ["lol"],
                0.0,
            ],
            [
                'int',
                '',
                '1000',
                1000,
            ],
            [
                'int',
                '',
                0xFFA,
                0xFFA,
            ],
            [
                'int',
                '',
                "lol",
                0,
            ],
            [
                'int',
                '',
                '!100a019.01a',
                10001901,
            ],
            [
                'int',
                'int',
                [1000],
                1000,
            ],
            [
                'int',
                'int',
                [0xFFA],
                0xFFA,
            ],
            [
                'int',
                'int',
                ["lol"],
                0,
            ],
            [
                'int',
                'int',
                ['!100a019.01a'],
                10001901,
            ],
            [
                'lower',
                '',
                'test',
                'test',
            ],
            [
                'lower',
                '',
                'tEsT',
                'test',
            ],
            [
                'lower',
                '',
                "TEST",
                'test',
            ],
            [
                'lower',
                'lower',
                ['test'],
                'test',
            ],
            [
                'lower',
                'lower',
                ['tEsT'],
                'test',
            ],
            [
                'lower',
                'lower',
                ["TEST"],
                'test',
            ],
            [
                'lowerfirst',
                '',
                'test',
                'test',
            ],
            [
                'lowerfirst',
                '',
                'tEsT',
                'tEsT',
            ],
            [
                'lowerfirst',
                '',
                "TEST",
                'tEST',
            ],
            [
                'lowerfirst',
                'lowerfirst',
                ['test'],
                'test',
            ],
            [
                'lowerfirst',
                'lowerfirst',
                ['tEsT'],
                'tEsT',
            ],
            [
                'lowerfirst',
                'lowerfirst',
                ["TEST"],
                'tEST',
            ],
            [
                'regex',
                '',
                ['mary abc a little lamb', '/abc/', 'had'],
                'mary had a little lamb',
            ],
            [
                'regex',
                'regex',
                ['mary abc a little lamb', '/abc/', 'had'],
                'mary had a little lamb',
            ],
            [
                'remove',
                '',
                ['mary had a little lamb', 'a'],
                'mry hd  little lmb',
            ],
            [
                'remove',
                'remove',
                ['mary had a little lamb', 'a'],
                'mry hd  little lmb',
            ],
            [
                'replace',
                '',
                ['test test', 'e', 'a'],
                'tast tast',
            ],
            [
                'replace',
                '',
                ['tEsT tEsT', 'E', 'A'],
                'tAsT tAsT',
            ],
            [
                'replace',
                '',
                ['TEST TEST', 'E', 'A'],
                'TAST TAST',
            ],
            [
                'replace',
                'replace',
                ['test test', 'e', 'a'],
                'tast tast',
            ],
            [
                'replace',
                'replace',
                ['tEsT tEsT', 'E', 'A'],
                'tAsT tAsT',
            ],
            [
                'replace',
                'replace',
                ['TEST TEST', 'E', 'A'],
                'TAST TAST',
            ],
            [
                'special',
                '',
                ['This is <html> tags'],
                'This is &#60;html&#62; tags',
            ],
            [
                'special',
                'special',
                ['This is <html> tags'],
                'This is &#60;html&#62; tags',
            ],
            [
                'specialfull',
                '',
                ['This is <html> tags'],
                'This is &lt;html&gt; tags',
            ],
            [
                'specialfull',
                'specialfull',
                ['This is <html> tags'],
                'This is &lt;html&gt; tags',
            ],
            [
                'string',
                '',
                'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+<>',
                'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&amp;*()_ `~=+&lt;&gt;',
            ],
            [
                'string',
                '',
                '{[<within french quotes>]}',
                '{[&lt;within french quotes&gt;]}',
            ],
            [
                'string',
                '',
                '',
                '',
            ],
            [
                'string',
                '',
                'buenos días123καλημέρα!@#$%^&*早安()_ `~=+<>',
                'buenos días123καλημέρα!@#$%^&amp;*早安()_ `~=+&lt;&gt;',
            ],
            [
                'string',
                '',
                '{[<buenos días 123 καλημέρα! 早安>]}',
                '{[&lt;buenos días 123 καλημέρα! 早安&gt;]}',
            ],
            [
                'string',
                'string',
                ['abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+<>'],
                'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&amp;*()_ `~=+&lt;&gt;',
            ],
            [
                'string',
                'string',
                ['{[<within french quotes>]}'],
                '{[&lt;within french quotes&gt;]}',
            ],
            [
                'string',
                'string',
                [''],
                '',
            ],
            [
                'string',
                'string',
                ['buenos días123καλημέρα!@#$%^&*早安()_ `~=+<>'],
                'buenos días123καλημέρα!@#$%^&amp;*早安()_ `~=+&lt;&gt;',
            ],
            [
                'string',
                'string',
                ['{[<buenos días 123 καλημέρα! 早安>]}'],
                '{[&lt;buenos días 123 καλημέρα! 早安&gt;]}',
            ],
            [
                'striptags',
                '',
                '<h1>Hello</h1>',
                'Hello',
            ],
            [
                'striptags',
                '',
                '<h1><p>Hello</h1>',
                'Hello',
            ],
            [
                'striptags',
                '',
                "<",
                '',
            ],
            [
                'striptags',
                'striptags',
                ['<h1>Hello</h1>'],
                'Hello',
            ],
            [
                'striptags',
                'striptags',
                ['<h1><p>Hello</h1>'],
                'Hello',
            ],
            [
                'striptags',
                'striptags',
                ["<"],
                '',
            ],
            [
                'trim',
                '',
                '    Hello',
                'Hello',
            ],
            [
                'trim',
                '',
                'Hello    ',
                'Hello',
            ],
            [
                'trim',
                '',
                "  Hello    ",
                'Hello',
            ],
            [
                'trim',
                'trim',
                ['    Hello'],
                'Hello',
            ],
            [
                'trim',
                'trim',
                ['Hello    '],
                'Hello',
            ],
            [
                'trim',
                'trim',
                ["  Hello    "],
                'Hello',
            ],
            [
                'upper',
                '',
                'test',
                'TEST',
            ],
            [
                'upper',
                '',
                'tEsT',
                'TEST',
            ],
            [
                'upper',
                '',
                "TEST",
                'TEST',
            ],
            [
                'upper',
                'upper',
                ['test'],
                'TEST',
            ],
            [
                'upper',
                'upper',
                ['tEsT'],
                'TEST',
            ],
            [
                'upper',
                'upper',
                ["TEST"],
                'TEST',
            ],
            [
                'upperfirst',
                '',
                'test',
                'Test',
            ],
            [
                'upperfirst',
                '',
                'tEsT',
                'TEsT',
            ],
            [
                'upperfirst',
                '',
                "TEST",
                'TEST',
            ],
            [
                'upperfirst',
                'upperfirst',
                ['test'],
                'Test',
            ],
            [
                'upperfirst',
                'upperfirst',
                ['tEsT'],
                'TEsT',
            ],
            [
                'upperfirst',
                'upperfirst',
                ["TEST"],
                'TEST',
            ],
            [
                'upperwords',
                '',
                'mary had a little lamb',
                'Mary Had A Little Lamb',
            ],
            [
                'upperwords',
                'upperwords',
                ['mary had a little lamb'],
                'Mary Had A Little Lamb',
            ],
            [
                'url',
                '',
                'https://pha�lc�on.i�o',
                'https://phalcon.io',
            ],
            [
                'url',
                'url',
                ['https://pha�lc�on.i�o'],
                'https://phalcon.io',
            ],*/
            // IPv4 Test dataset
            [
                'ip',
                '',
                ['192.168.0.10', 0],
                '192.168.0.10',
            ],
            [
                'ip',
                '',
                ['255.255.255.255', 0],
                '255.255.255.255',
            ],
            [
                'ip',
                '',
                ['10.0.0.0/24', 0],
                '10.0.0.0/24',
            ],
            [
                'ip',
                '',
                ['8.8.8.8'],
                '8.8.8.8',
            ],
            [
                'ip',
                '',
                ['192.168.1.1', FILTER_FLAG_NO_PRIV_RANGE],
                false,
            ],
            [
                'ip',
                '',
                ['10.0.0.5', FILTER_FLAG_NO_PRIV_RANGE],
                false,
            ],
            [
                'ip',
                '',
                ['0.0.0.0', FILTER_FLAG_NO_RES_RANGE],
                false,
            ],
            [
                'ip',
                '',
                ['255.255.255.255', FILTER_FLAG_NO_RES_RANGE],
                false,
            ],
            [
                'ip',
                '',
                ['255.255.255.255', FILTER_FLAG_NO_RES_RANGE | FILTER_FLAG_NO_PRIV_RANGE],
                false,
            ],
            [
                'ip',
                '',
                ['999.999.999.999', FILTER_FLAG_IPV4],
                false,
            ],
            [
                'ip',
                '',
                ['192.168.1.1/33', FILTER_FLAG_IPV4],
                false,
            ],
            // IPv6 Test dataset
            [
                'ip',
                '',
                ['2001:4860:4860::8888', 0],
                '2001:4860:4860::8888',
            ],
            [
                'ip',
                '',
                ['2001:db8::1', FILTER_FLAG_IPV6],
                '2001:db8::1',
            ],
            [
                'ip',
                '',
                ['2001:db8::/32', 0],
                '2001:db8::/32',
            ],
            [
                'ip',
                '',
                ['2001:db8:85a3:8d3:1319:8a2e:370:7348'],
                '2001:db8:85a3:8d3:1319:8a2e:370:7348',
            ],
            [
                'ip',
                '',
                ['fd12:3456:789a:1::1', FILTER_FLAG_NO_PRIV_RANGE],
                false,
            ],
            [
                'ip',
                '',
                ['fc00::1', FILTER_FLAG_NO_PRIV_RANGE],
                false,
            ],
            [
                'ip',
                '',
                ['fe80::1', FILTER_FLAG_NO_RES_RANGE],
                false,
            ],
            [
                'ip',
                '',
                ['::1', FILTER_FLAG_NO_RES_RANGE],
                false,
            ],
            [
                'ip',
                '',
                ['fd00::1', FILTER_FLAG_NO_RES_RANGE | FILTER_FLAG_NO_PRIV_RANGE],
                false,
            ],
            [
                'ip',
                '',
                ['2001:db8:85a3::8a2e:370g:7334', FILTER_FLAG_IPV6],
                false,
            ],
            [
                'ip',
                '',
                ['2001:db8::/140', FILTER_FLAG_IPV6],
                false,
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-11-07
     */
    public function testFilterFilterSanitize(
        string $class,
        string $method,
        mixed $source,
        mixed $expected
    ): void {
        $factory = new FilterFactory();
        $filter  = $factory->newInstance();
        if (true === empty($method)) {
            $sanitizer = $filter->get($class);
            if (is_array($source)) {
                $actual = call_user_func_array([$sanitizer, '__invoke'], $source);
            } else {
                $actual = $sanitizer->__invoke($source);
            }
        } else {
            $actual = call_user_func_array([$filter, $method], $source);
        }

        $this->assertEquals($expected, $actual);
    }
}

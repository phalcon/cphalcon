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

use Codeception\Example;
use Phalcon\Filter\FilterFactory;
use UnitTester;

use function call_user_func_array;
use function implode;
use function is_array;
use function phpversion;
use function version_compare;

class SanitizeCest
{
    /**
     * Tests Phalcon\Filter\Sanitize\*t :: __invoke()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-11-07
     */
    public function filterSanitize(UnitTester $I, Example $example)
    {
        $class  = $example['class'];
        $label  = $example['label'];
        $source = $example['source'];
        $method = $example['method'];

        $I->wantToTest(
            sprintf(
                'Filter\Sanitize\* = %s - %s : "%s"',
                $class,
                $label,
                (is_array($source) ? implode(":", $source) : (string)$source)
            )
        );

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

        /**
         * @todo This stays here for until 7.4/8.0 are deprecated.
         */
        $expected = $example['expected'];
        if (
            'stringlegacy' === $class &&
            version_compare(phpversion(), "8.1", ">=")
        ) {
            $expected = is_array($source) ? $source[0] : $source;
        }

        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array[]
     */
    private function getExamples(): array
    {
        return [
            [
                'class'    => 'absint',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => -125,
                'expected' => 125,
            ],
            [
                'class'    => 'absint',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => -125,
                'expected' => 125,
            ],
            [
                'class'    => 'absint',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => -125,
                'expected' => 125,
            ],
            [
                'class'    => 'absint',
                'label'    => 'absint()',
                'method'   => 'absint',
                'source'   => [-125],
                'expected' => 125,
            ],
            [
                'class'    => 'absint',
                'label'    => 'absint()',
                'method'   => 'absint',
                'source'   => [-125],
                'expected' => 125,
            ],
            [
                'class'    => 'absint',
                'label'    => 'absint()',
                'method'   => 'absint',
                'source'   => [-125],
                'expected' => 125,
            ],
            [
                'class'    => 'alnum',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '0',
                'expected' => '0',
            ],
            [
                'class'    => 'alnum',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '',
                'expected' => '',
            ],
            [
                'class'    => 'alnum',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '?a&5xka\tŧ?1-s.Xa[\n',
                'expected' => 'a5xkat1sXan',
            ],
            [
                'class'    => 'alnum',
                'label'    => 'alnum()',
                'method'   => 'alnum',
                'source'   => ['0'],
                'expected' => '0',
            ],
            [
                'class'    => 'alnum',
                'label'    => 'alnum()',
                'method'   => 'alnum',
                'source'   => [''],
                'expected' => '',
            ],
            [
                'class'    => 'alnum',
                'label'    => 'alnum()',
                'method'   => 'alnum',
                'source'   => ['?a&5xka\tŧ?1-s.Xa[\n'],
                'expected' => 'a5xkat1sXan',
            ],
            [
                'class'    => 'alpha',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '0',
                'expected' => '',
            ],
            [
                'class'    => 'alpha',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '',
                'expected' => '',
            ],
            [
                'class'    => 'alpha',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '?a&5xka\tŧ?1-s.Xa[\n',
                'expected' => 'axkatsXan',
            ],
            [
                'class'    => 'alpha',
                'label'    => 'alpha()',
                'method'   => 'alpha',
                'source'   => ['0'],
                'expected' => '',
            ],
            [
                'class'    => 'alpha',
                'label'    => 'alpha()',
                'method'   => 'alpha',
                'source'   => [''],
                'expected' => '',
            ],
            [
                'class'    => 'alpha',
                'label'    => 'alpha()',
                'method'   => 'alpha',
                'source'   => ['?a&5xka\tŧ?1-s.Xa[\n'],
                'expected' => 'axkatsXan',
            ],
            [
                'class'    => 'bool',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 1000,
                'expected' => true,
            ],
            [
                'class'    => 'bool',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 0xFFA,
                'expected' => true,
            ],
            [
                'class'    => 'bool',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '1000',
                'expected' => true,
            ],
            [
                'class'    => 'bool',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => null,
                'expected' => false,
            ],
            [
                'class'    => 'bool',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'on',
                'expected' => true,
            ],
            [
                'class'    => 'bool',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'off',
                'expected' => false,
            ],
            [
                'class'    => 'bool',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'yes',
                'expected' => true,
            ],
            [
                'class'    => 'bool',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'no',
                'expected' => false,
            ],
            [
                'class'    => 'bool',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'y',
                'expected' => true,
            ],
            [
                'class'    => 'bool',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'n',
                'expected' => false,
            ],
            [
                'class'    => 'bool',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 0,
                'expected' => false,
            ],
            [
                'class'    => 'bool',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 1,
                'expected' => true,
            ],
            [
                'class'    => 'bool',
                'label'    => 'bool()',
                'method'   => 'bool',
                'source'   => [1000],
                'expected' => true,
            ],
            [
                'class'    => 'bool',
                'label'    => 'bool()',
                'method'   => 'bool',
                'source'   => [0xFFA],
                'expected' => true,
            ],
            [
                'class'    => 'bool',
                'label'    => 'bool()',
                'method'   => 'bool',
                'source'   => ['1000'],
                'expected' => true,
            ],
            [
                'class'    => 'bool',
                'label'    => 'bool()',
                'method'   => 'bool',
                'source'   => [null],
                'expected' => false,
            ],
            [
                'class'    => 'bool',
                'label'    => 'bool()',
                'method'   => 'bool',
                'source'   => ['on'],
                'expected' => true,
            ],
            [
                'class'    => 'bool',
                'label'    => 'bool()',
                'method'   => 'bool',
                'source'   => ['off'],
                'expected' => false,
            ],
            [
                'class'    => 'bool',
                'label'    => 'bool()',
                'method'   => 'bool',
                'source'   => ['yes'],
                'expected' => true,
            ],
            [
                'class'    => 'bool',
                'label'    => 'bool()',
                'method'   => 'bool',
                'source'   => ['no'],
                'expected' => false,
            ],
            [
                'class'    => 'bool',
                'label'    => 'bool()',
                'method'   => 'bool',
                'source'   => ['y'],
                'expected' => true,
            ],
            [
                'class'    => 'bool',
                'label'    => 'bool()',
                'method'   => 'bool',
                'source'   => ['n'],
                'expected' => false,
            ],
            [
                'class'    => 'bool',
                'label'    => 'bool()',
                'method'   => 'bool',
                'source'   => [1],
                'expected' => true,
            ],
            [
                'class'    => 'bool',
                'label'    => 'bool()',
                'method'   => 'bool',
                'source'   => [0],
                'expected' => false,
            ],
            [
                'class'    => 'email',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => "some(one)@exa\\mple.com",
                'expected' => 'someone@example.com',
            ],
            [
                'class'    => 'email',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => "!(first.guy)
                    @*my-domain**##.com.rx//",
                'expected' => "!first.guy@*my-domain**##.com.rx",
            ],
            [
                'class'    => 'email',
                'label'    => 'email()',
                'method'   => 'email',
                'source'   => ["some(one)@exa\\mple.com"],
                'expected' => 'someone@example.com',
            ],
            [
                'class'    => 'email',
                'label'    => 'email()',
                'method'   => 'email',
                'source'   => [
                    "!(first.guy)
                    @*my-domain**##.com.rx//",
                ],
                'expected' => "!first.guy@*my-domain**##.com.rx",
            ],
            [
                'class'    => 'float',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '1000.01',
                'expected' => 1000.01,
            ],
            [
                'class'    => 'float',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 0xFFA,
                'expected' => 0xFFA,
            ],
            [
                'class'    => 'float',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => "lol",
                'expected' => 0.0,
            ],
            [
                'class'    => 'float',
                'label'    => 'float()',
                'method'   => 'float',
                'source'   => ['1000.01'],
                'expected' => 1000.01,
            ],
            [
                'class'    => 'float',
                'label'    => 'float()',
                'method'   => 'float',
                'source'   => [0xFFA],
                'expected' => 0xFFA,
            ],
            [
                'class'    => 'float',
                'label'    => 'float()',
                'method'   => 'float',
                'source'   => ["lol"],
                'expected' => 0.0,
            ],
            [
                'class'    => 'int',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '1000',
                'expected' => 1000,
            ],
            [
                'class'    => 'int',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 0xFFA,
                'expected' => 0xFFA,
            ],
            [
                'class'    => 'int',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => "lol",
                'expected' => 0,
            ],
            [
                'class'    => 'int',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '!100a019.01a',
                'expected' => 10001901,
            ],
            [
                'class'    => 'int',
                'label'    => 'int()',
                'method'   => 'int',
                'source'   => [1000],
                'expected' => 1000,
            ],
            [
                'class'    => 'int',
                'label'    => 'int()',
                'method'   => 'int',
                'source'   => [0xFFA],
                'expected' => 0xFFA,
            ],
            [
                'class'    => 'int',
                'label'    => 'int()',
                'method'   => 'int',
                'source'   => ["lol"],
                'expected' => 0,
            ],
            [
                'class'    => 'int',
                'label'    => 'int()',
                'method'   => 'int',
                'source'   => ['!100a019.01a'],
                'expected' => 10001901,
            ],
            [
                'class'    => 'lower',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'test',
                'expected' => 'test',
            ],
            [
                'class'    => 'lower',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'tEsT',
                'expected' => 'test',
            ],
            [
                'class'    => 'lower',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => "TEST",
                'expected' => 'test',
            ],
            [
                'class'    => 'lower',
                'label'    => 'lower()',
                'method'   => 'lower',
                'source'   => ['test'],
                'expected' => 'test',
            ],
            [
                'class'    => 'lower',
                'label'    => 'lower()',
                'method'   => 'lower',
                'source'   => ['tEsT'],
                'expected' => 'test',
            ],
            [
                'class'    => 'lower',
                'label'    => 'lower()',
                'method'   => 'lower',
                'source'   => ["TEST"],
                'expected' => 'test',
            ],
            [
                'class'    => 'lowerfirst',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'test',
                'expected' => 'test',
            ],
            [
                'class'    => 'lowerfirst',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'tEsT',
                'expected' => 'tEsT',
            ],
            [
                'class'    => 'lowerfirst',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => "TEST",
                'expected' => 'tEST',
            ],
            [
                'class'    => 'lowerfirst',
                'label'    => 'lowerfirst()',
                'method'   => 'lowerfirst',
                'source'   => ['test'],
                'expected' => 'test',
            ],
            [
                'class'    => 'lowerfirst',
                'label'    => 'lowerfirst()',
                'method'   => 'lowerfirst',
                'source'   => ['tEsT'],
                'expected' => 'tEsT',
            ],
            [
                'class'    => 'lowerfirst',
                'label'    => 'lowerfirst()',
                'method'   => 'lowerfirst',
                'source'   => ["TEST"],
                'expected' => 'tEST',
            ],
            [
                'class'    => 'regex',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => ['mary abc a little lamb', '/abc/', 'had'],
                'expected' => 'mary had a little lamb',
            ],
            [
                'class'    => 'regex',
                'label'    => 'regex()',
                'method'   => 'regex',
                'source'   => ['mary abc a little lamb', '/abc/', 'had'],
                'expected' => 'mary had a little lamb',
            ],
            [
                'class'    => 'remove',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => ['mary had a little lamb', 'a'],
                'expected' => 'mry hd  little lmb',
            ],
            [
                'class'    => 'remove',
                'label'    => 'remove()',
                'method'   => 'remove',
                'source'   => ['mary had a little lamb', 'a'],
                'expected' => 'mry hd  little lmb',
            ],
            [
                'class'    => 'replace',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => ['test test', 'e', 'a'],
                'expected' => 'tast tast',
            ],
            [
                'class'    => 'replace',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => ['tEsT tEsT', 'E', 'A'],
                'expected' => 'tAsT tAsT',
            ],
            [
                'class'    => 'replace',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => ['TEST TEST', 'E', 'A'],
                'expected' => 'TAST TAST',
            ],
            [
                'class'    => 'replace',
                'label'    => 'replace()',
                'method'   => 'replace',
                'source'   => ['test test', 'e', 'a'],
                'expected' => 'tast tast',
            ],
            [
                'class'    => 'replace',
                'label'    => 'replace()',
                'method'   => 'replace',
                'source'   => ['tEsT tEsT', 'E', 'A'],
                'expected' => 'tAsT tAsT',
            ],
            [
                'class'    => 'replace',
                'label'    => 'replace()',
                'method'   => 'replace',
                'source'   => ['TEST TEST', 'E', 'A'],
                'expected' => 'TAST TAST',
            ],
            [
                'class'    => 'special',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => ['This is <html> tags'],
                'expected' => 'This is &#60;html&#62; tags',
            ],
            [
                'class'    => 'special',
                'label'    => 'special()',
                'method'   => 'special',
                'source'   => ['This is <html> tags'],
                'expected' => 'This is &#60;html&#62; tags',
            ],
            [
                'class'    => 'specialfull',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => ['This is <html> tags'],
                'expected' => 'This is &lt;html&gt; tags',
            ],
            [
                'class'    => 'specialfull',
                'label'    => 'specialfull()',
                'method'   => 'specialfull',
                'source'   => ['This is <html> tags'],
                'expected' => 'This is &lt;html&gt; tags',
            ],
            [
                'class'    => 'string',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+<>',
                'expected' => 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&amp;*()_ `~=+&lt;&gt;',
            ],
            [
                'class'    => 'string',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '{[<within french quotes>]}',
                'expected' => '{[&lt;within french quotes&gt;]}',
            ],
            [
                'class'    => 'string',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '',
                'expected' => '',
            ],
            [
                'class'    => 'string',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+<>',
                'expected' => 'buenos días123καλημέρα!@#$%^&amp;*早安()_ `~=+&lt;&gt;',
            ],
            [
                'class'    => 'string',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '{[<buenos días 123 καλημέρα! 早安>]}',
                'expected' => '{[&lt;buenos días 123 καλημέρα! 早安&gt;]}',
            ],
            [
                'class'    => 'string',
                'label'    => 'string()',
                'method'   => 'string',
                'source'   => ['abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+<>'],
                'expected' => 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&amp;*()_ `~=+&lt;&gt;',
            ],
            [
                'class'    => 'string',
                'label'    => 'string()',
                'method'   => 'string',
                'source'   => ['{[<within french quotes>]}'],
                'expected' => '{[&lt;within french quotes&gt;]}',
            ],
            [
                'class'    => 'string',
                'label'    => 'string()',
                'method'   => 'string',
                'source'   => [''],
                'expected' => '',
            ],
            [
                'class'    => 'string',
                'label'    => 'string()',
                'method'   => 'string',
                'source'   => ['buenos días123καλημέρα!@#$%^&*早安()_ `~=+<>'],
                'expected' => 'buenos días123καλημέρα!@#$%^&amp;*早安()_ `~=+&lt;&gt;',
            ],
            [
                'class'    => 'string',
                'label'    => 'string()',
                'method'   => 'string',
                'source'   => ['{[<buenos días 123 καλημέρα! 早安>]}'],
                'expected' => '{[&lt;buenos días 123 καλημέρα! 早安&gt;]}',
            ],
            [
                'class'    => 'stringlegacy',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+<>',
                'expected' => 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+',
            ],
            [
                'class'    => 'stringlegacy',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '{[<within french quotes>]}',
                'expected' => '{[]}',
            ],
            [
                'class'    => 'stringlegacy',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '',
                'expected' => '',
            ],
            [
                'class'    => 'stringlegacy',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+<>',
                'expected' => 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+',
            ],
            [
                'class'    => 'stringlegacy',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '{[<buenos días 123 καλημέρα! 早安>]}',
                'expected' => '{[]}',
            ],
            [
                'class'    => 'stringlegacy',
                'label'    => 'stringlegacy()',
                'method'   => 'stringlegacy',
                'source'   => ['abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+<>'],
                'expected' => 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+',
            ],
            [
                'class'    => 'stringlegacy',
                'label'    => 'stringlegacy()',
                'method'   => 'stringlegacy',
                'source'   => ['{[<within french quotes>]}'],
                'expected' => '{[]}',
            ],
            [
                'class'    => 'stringlegacy',
                'label'    => 'stringlegacy()',
                'method'   => 'stringlegacy',
                'source'   => [''],
                'expected' => '',
            ],
            [
                'class'    => 'stringlegacy',
                'label'    => 'stringlegacy()',
                'method'   => 'stringlegacy',
                'source'   => ['buenos días123καλημέρα!@#$%^&*早安()_ `~=+<>'],
                'expected' => 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+',
            ],
            [
                'class'    => 'stringlegacy',
                'label'    => 'stringlegacy()',
                'method'   => 'stringlegacy',
                'source'   => ['{[<buenos días 123 καλημέρα! 早安>]}'],
                'expected' => '{[]}',
            ],
            [
                'class'    => 'striptags',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '<h1>Hello</h1>',
                'expected' => 'Hello',
            ],
            [
                'class'    => 'striptags',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '<h1><p>Hello</h1>',
                'expected' => 'Hello',
            ],
            [
                'class'    => 'striptags',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => "<",
                'expected' => '',
            ],
            [
                'class'    => 'striptags',
                'label'    => 'striptags()',
                'method'   => 'striptags',
                'source'   => ['<h1>Hello</h1>'],
                'expected' => 'Hello',
            ],
            [
                'class'    => 'striptags',
                'label'    => 'striptags()',
                'method'   => 'striptags',
                'source'   => ['<h1><p>Hello</h1>'],
                'expected' => 'Hello',
            ],
            [
                'class'    => 'striptags',
                'label'    => 'striptags()',
                'method'   => 'striptags',
                'source'   => ["<"],
                'expected' => '',
            ],
            [
                'class'    => 'trim',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => '    Hello',
                'expected' => 'Hello',
            ],
            [
                'class'    => 'trim',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'Hello    ',
                'expected' => 'Hello',
            ],
            [
                'class'    => 'trim',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => "  Hello    ",
                'expected' => 'Hello',
            ],
            [
                'class'    => 'trim',
                'label'    => 'trim()',
                'method'   => 'trim',
                'source'   => ['    Hello'],
                'expected' => 'Hello',
            ],
            [
                'class'    => 'trim',
                'label'    => 'trim()',
                'method'   => 'trim',
                'source'   => ['Hello    '],
                'expected' => 'Hello',
            ],
            [
                'class'    => 'trim',
                'label'    => 'trim()',
                'method'   => 'trim',
                'source'   => ["  Hello    "],
                'expected' => 'Hello',
            ],
            [
                'class'    => 'upper',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'test',
                'expected' => 'TEST',
            ],
            [
                'class'    => 'upper',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'tEsT',
                'expected' => 'TEST',
            ],
            [
                'class'    => 'upper',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => "TEST",
                'expected' => 'TEST',
            ],
            [
                'class'    => 'upper',
                'label'    => 'upper()',
                'method'   => 'upper',
                'source'   => ['test'],
                'expected' => 'TEST',
            ],
            [
                'class'    => 'upper',
                'label'    => 'upper()',
                'method'   => 'upper',
                'source'   => ['tEsT'],
                'expected' => 'TEST',
            ],
            [
                'class'    => 'upper',
                'label'    => 'upper()',
                'method'   => 'upper',
                'source'   => ["TEST"],
                'expected' => 'TEST',
            ],
            [
                'class'    => 'upperfirst',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'test',
                'expected' => 'Test',
            ],
            [
                'class'    => 'upperfirst',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'tEsT',
                'expected' => 'TEsT',
            ],
            [
                'class'    => 'upperfirst',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => "TEST",
                'expected' => 'TEST',
            ],
            [
                'class'    => 'upperfirst',
                'label'    => 'upperfirst()',
                'method'   => 'upperfirst',
                'source'   => ['test'],
                'expected' => 'Test',
            ],
            [
                'class'    => 'upperfirst',
                'label'    => 'upperfirst()',
                'method'   => 'upperfirst',
                'source'   => ['tEsT'],
                'expected' => 'TEsT',
            ],
            [
                'class'    => 'upperfirst',
                'label'    => 'upperfirst()',
                'method'   => 'upperfirst',
                'source'   => ["TEST"],
                'expected' => 'TEST',
            ],
            [
                'class'    => 'upperwords',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'mary had a little lamb',
                'expected' => 'Mary Had A Little Lamb',
            ],
            [
                'class'    => 'upperwords',
                'label'    => 'upperwords()',
                'method'   => 'upperwords',
                'source'   => ['mary had a little lamb'],
                'expected' => 'Mary Had A Little Lamb',
            ],
            [
                'class'    => 'url',
                'label'    => '__invoke()',
                'method'   => '',
                'source'   => 'https://pha�lc�on.i�o',
                'expected' => 'https://phalcon.io',
            ],
            [
                'class'    => 'url',
                'label'    => 'url()',
                'method'   => 'url',
                'source'   => ['https://pha�lc�on.i�o'],
                'expected' => 'https://phalcon.io',
            ],
        ];
    }
}

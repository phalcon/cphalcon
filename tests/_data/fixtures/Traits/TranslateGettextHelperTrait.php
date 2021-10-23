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

namespace Phalcon\Tests\Fixtures\Traits;

use Codeception\Example;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

use function sprintf;

trait TranslateGettextHelperTrait
{
    /**
     * @return string
     */
    abstract protected function func(): string;

    /**
     * @return array
     */
    abstract protected function getGettextConfig(): array;

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: query()
     *
     * @dataProvider getQueryProvider
     *
     * @param UnitTester $I
     * @param Example    $data
     *
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterGettextQuery(UnitTester $I, Example $data)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\Gettext - %s - %s',
                $this->func(),
                $data['language']
            )
        );

        $language   = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $language);

        foreach ($data['tests'] as $key => $expected) {
            $actual = $translator->{$this->func()}($key);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: query() -
     * variable substitution in string with no variables
     *
     * @dataProvider getQueryProvider
     *
     * @param UnitTester $I
     * @param Example    $data
     *
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterGettextVariableSubstitutionNoVariables(
        UnitTester $I,
        Example $data
    ) {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\Gettext - variable substitution no variables - %s',
                $data['language']
            )
        );

        $language   = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $language);

        foreach ($data['tests'] as $key => $expected) {
            $actual = $translator->{$this->func()}(
                $key,
                [
                    'name' => 'my friend',
                ]
            );
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: query() -
     * variable substitution in string (one variable)
     *
     * @dataProvider getQueryOneVariable
     *
     * @param UnitTester $I
     * @param Example    $data
     *
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterGettextVariableSubstitutionOneVariable(
        UnitTester $I,
        Example $data
    ) {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\Gettext - variable substitution one variable - %s',
                $data['language']
            )
        );

        $language   = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $language);

        foreach ($data['tests'] as $key => $expected) {
            $actual = $translator->{$this->func()}($key, ['name' => 'my friend']);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: query() -
     * variable substitution in string (two variables)
     *
     * @dataProvider getQueryTwoVariables
     *
     * @param UnitTester $I
     * @param Example    $data
     *
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterGettextVariableSubstitutionTwoVariable(
        UnitTester $I,
        Example $data
    ) {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\Gettext - variable substitution two variables - %s',
                $data['language']
            )
        );

        $language   = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $language);

        $vars = [
            'song'   => 'Dust in the wind',
            'artist' => 'Kansas',
        ];

        foreach ($data['tests'] as $key => $expected) {
            $actual = $translator->{$this->func()}($key, $vars);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: query() - array access and
     * UTF8 strings
     *
     * @param UnitTester $I
     *
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testWithArrayAccessAndUTF8Strings(UnitTester $I)
    {
        $language = $this->getGettextConfig();

        $translator = new Gettext(new InterpolatorFactory(), $language);

        $vars = [
            'fname' => 'John',
            'lname' => 'Doe',
            'mname' => 'D.',
        ];

        $expected = 'Привет, John D. Doe!';
        $actual   = $translator->{$this->func()}('Привет, %fname% %mname% %lname%!', $vars);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Data provider for the query tests
     *
     * @return array[]
     */
    private function getQueryProvider(): array
    {
        return [
            [
                'language' => 'English',
                'code'     => 'en',
                'tests'    => [
                    'hi'  => 'Hello',
                    'bye' => 'Bye',
                ],
            ],
        ];
    }

    /**
     * Data provider for the query one variable substitution
     *
     * @return array[]
     */
    private function getQueryOneVariable(): array
    {
        return [
            [
                'language' => 'English',
                'code'     => 'en',
                'tests'    => [
                    'hello-key' => 'Hello my friend',
                ],
            ],
        ];
    }

    /**
     * Data provider for the query one variable substitution
     *
     * @return array[]
     */
    private function getQueryTwoVariables(): array
    {
        return [
            [
                'language' => 'English',
                'code'     => 'en',
                'tests'    => [
                    'song-key' => 'The song is Dust in the wind (Kansas)',
                ],
            ],
        ];
    }
}

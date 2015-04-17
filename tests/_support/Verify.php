<?php

namespace Codeception;

use \PHPUnit_Framework_Assert as a;

class Verify
{

    protected $actual = null;
    protected $description = '';

    public function __construct($description, $actual = null)
    {
        if (!$actual) {
            $this->actual = $description;
        } else {
            $this->actual = $actual;
            $this->description = $description;
        }
    }

    public function equals($expected)
    {
        a::assertEquals($expected, $this->actual, $this->description);
    }

    public function notEquals($expected)
    {
        a::assertNotEquals($expected, $this->actual, $this->description);
    }

    public function contains($needle)
    {
        a::assertContains($needle, $this->actual, $this->description);
    }

    public function notContains($needle)
    {
        a::assertNotContains($needle, $this->actual, $this->description);
    }

    public function greaterThan($expected)
    {
        a::assertGreaterThan($expected, $this->actual, $this->description);
    }

    public function lessThen($expected)
    {
        a::assertLessThan($expected, $this->actual, $this->description);
    }

    public function greaterOrEquals($expected)
    {
        a::assertGreaterThanOrEqual($expected, $this->actual, $this->description);
    }

    public function lessOrEquals($expected)
    {
        a::assertLessThanOrEqual($expected, $this->actual, $this->description);
    }

    public function true()
    {
        a::assertTrue($this->actual, $this->description);
    }

    public function false()
    {
        a::assertFalse($this->actual, $this->description);
    }

    public function null()
    {
        a::assertNull($this->actual, $this->description);
    }

    public function notNull()
    {
        a::assertNotNull($this->actual, $this->description);
    }

    public function isEmpty()
    {
        a::assertEmpty($this->actual, $this->description);
    }

    public function notEmpty()
    {
        a::assertNotEmpty($this->actual, $this->description);
    }

    public function hasKey($key)
    {
        a::assertArrayHasKey($key, $this->actual, $this->description);
    }

    public function hasntKey($key)
    {
        a::assertArrayNotHasKey($key, $this->actual, $this->description);
    }
}

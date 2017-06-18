<?php

namespace Phalcon\Test\Models\Annotations;

use Phalcon\Mvc\Model;


class Robot extends Model
{
    /**
     * @Primary
     * @Identity
     * @Column(type="biginteger")
     */
    protected $id;

    /**
     * @Column(type="varchar", length="70", allow_empty_string=true)
     */
    protected $name;

    /**
     * @Column(type="varchar", length="32", default="mechanical")
     */
    protected $type;

    /**
     * @Column(type="integer", default=1900)
     */
    protected $year;

    /**
     * @Column(type="datetime", nullable=true, skip_on_insert=true)
     */
    protected $deleted;

    /**
     * @Column(type="text", allow_empty_string=true, column="text")
     */
    protected $description;

    /**
     * @Column(type="float", skip_on_update=true)
     */
    protected $float;

    /**
     * @Column(type="double")
     */
    protected $double;

    /**
     * @Column(type="decimal")
     */
    protected $decimal;

    /**
     * @Column(type="boolean")
     */
    protected $activated;

    /**
     * @Column(type="date")
     */
    protected $birthday;

    /**
     * @Column(type="timestamp")
     */
    protected $timestamp;

    /**
     * @Column(type="char", length="10")
     */
    protected $code;

    /**
     * @Column(type="json", nullable=true)
     */
    protected $json;

    /**
     * @Column(type="tinyblob", nullable=true)
     */
    protected $tinyblob;

    /**
     * @Column(type="blob", nullable=true)
     */
    protected $blob;

    /**
     * @Column(type="mediumblob", nullable=true)
     */
    protected $mediumblob;

    /**
     * @Column(type="longblob", nullable=true, skip_on_update=true)
     */
    protected $longblob;

}

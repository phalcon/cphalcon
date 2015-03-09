<?php

use Phalcon\Mvc\Model\MetaData;
use Phalcon\Db\Column;

/**
 * Robotto is the japanese for Robot
 */
class Robotto extends Phalcon\Mvc\Model
{

	public function getSource()
	{
		return 'robots';
	}

	public function metaData()
	{
		return array(
			MetaData::MODELS_ATTRIBUTES => array(
				'id', 'name', 'type', 'year'
			),
			MetaData::MODELS_PRIMARY_KEY => array(
				'id'
			),
			MetaData::MODELS_NON_PRIMARY_KEY => array(
				'name', 'type', 'year'
			),
			MetaData::MODELS_NOT_NULL => array(
				'id', 'name', 'type', 'year'
			),
			MetaData::MODELS_DATA_TYPES => array(
				'id' => Column::TYPE_INTEGER,
				'name' => Column::TYPE_VARCHAR,
				'type' => Column::TYPE_VARCHAR,
				'year' => Column::TYPE_INTEGER
			),
			MetaData::MODELS_DATA_TYPES_NUMERIC => array(
				'id' => true,
				'year' => true,
			),
			MetaData::MODELS_IDENTITY_COLUMN => 'id',
			MetaData::MODELS_DATA_TYPES_BIND => array(
				'id' => Column::BIND_PARAM_INT,
				'name' => Column::BIND_PARAM_STR,
				'type' => Column::BIND_PARAM_STR,
				'year' => Column::BIND_PARAM_INT,
			),
			MetaData::MODELS_AUTOMATIC_DEFAULT_INSERT => array(),
			MetaData::MODELS_AUTOMATIC_DEFAULT_UPDATE => array()
		);
	}

}